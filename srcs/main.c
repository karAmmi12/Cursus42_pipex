/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:38:02 by kammi             #+#    #+#             */
/*   Updated: 2024/03/05 15:50:29 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_redirect(t_pipex *pipex, int i) //fonction qui redirige les entrées et sorties
{
	if (i != 0)
	{
		dup2(pipex->prev_fd, 0);//dupliquer le descripteur de fichier en lecture seule pour qu'il pointe sur le descripteur de fichier prev_fd
		close(pipex->prev_fd);

	}
	if (i != pipex->cmd_count - 1)
		dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	ft_open_file(t_pipex *pipex, int i)
{
	int	fd;

	if (i == 0)
		fd = open(pipex->infile, O_RDONLY); //ouvrir le fichier en lecture seule
	if (i == pipex->cmd_count - 1)
		fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);//ouvrir le fichier en écriture seule
	if (fd < 0)
	{
		ft_putstr_fd("Error: open failed\n", 2);
		exit(1);
	}
	dup2(fd, i == pipex->cmd_count - 1); //dupliquer le fichier afin qu'il pointe sur le descripteur de fichier i == pipex->cmd_count - 1
}

void	ft_execve(t_pipex *pipex, char *cmd)
{
	char	**split;

	//ft_putstr_fd(cmd, 2);
	//ft_putchar_fd('\n', 2);
	split = ft_split(cmd, ' ');
	if (!split)
		return ;
	cmd = ft_get_path(pipex->envp, split[0]);
	//ft_putstr_fd(cmd, 2);
	//ft_putchar_fd('\n', 2);
	if (!cmd)
	{
		ft_putstr_fd("Error: command not found\n", 2);
		free_tab(split);
		exit(1);
	}
	//ft_putstr_fd("je suis dans execve\n", 2);
	execve(cmd, split, pipex->envp);//remplacer le processus courant par un nouveau processus
	free_tab(split);
	free(cmd);

}
void	ft_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipe(pipex->fd); //créer un pipe pour la communication entre les processus
		pipex->pid[i] = fork(); //créer un processus fils
		if (pipex->pid[i] == -1)
			exit(1);

		if (pipex->pid[i] == 0)//processus fils
		{
			free(pipex->pid);//libérer la mémoire allouée à pid dans le processus fils
			ft_redirect(pipex, i); //fonction qui redirige les entrées et sorties
			if (i == 0 || i == pipex->cmd_count - 1)
				ft_open_file(pipex, i); //fonction qui ouvre les fichiers
			ft_execve(pipex, pipex->cmd[i]); //fonction qui exécute les commandes
			exit(127); //terminer le processus fils avec le code d'erreur 127 qui veut dire "command not found"
		}
		else//processus père
		{
			close(pipex->fd[1]);//fermer le descripteur de fichier en écriture
			if (i > 0)
				close(pipex->prev_fd);
			pipex->prev_fd = pipex->fd[0];
			i++;
		}
	}
	ft_waitpid(pipex); //fonction qui attend la fin des processus fils

}

int	main(int ac, char **av, char **envp)
{
	static t_pipex	pipex = {0};//initialiser la structure à 0

	if (ac != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (1);
	}
	ft_init_pipex(&pipex, av, envp, ac);
	pipex.pid = malloc(sizeof(int) * pipex.cmd_count);
	if (!pipex.pid)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (1);
	}
	ft_pipex(&pipex);
	free(pipex.pid);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
}
