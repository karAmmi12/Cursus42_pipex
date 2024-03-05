/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:04:52 by kammi             #+#    #+#             */
/*   Updated: 2024/03/05 15:41:25 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **av, char **envp, int ac)
{
	pipex->cmd_count = ac - 3;
	pipex->cmd = &av[2]; //
	pipex->envp = envp;
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
}

char	*ft_find_path(char **split, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_tab(split);
			return (path);
		}
		free(path);
		i++;
	}
	free_tab(split);
	return (NULL);
}

char	*ft_get_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**split;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			split = ft_split(path, ':');
			free(path);
			path = ft_find_path(split, cmd);
			if (path)
				return (path);
		}
		i++;
	}
	return (NULL);
}

/* char	*ft_get_path(char **envp, char *cmd)
{
	int		i;
	int		j;
	char	*path;
	char	**split;


	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)//comparer les deux chaînes
		{
			path = ft_strdup(envp[i] + 5);//dupliquer la chaîne
			//ft_putstr_fd(path, 2);
			split = ft_split(path, ':');//séparer la chaîne en fonction du caractère :
			free(path);
			j = 0;
			while (split[j])
			{
				path = ft_strjoin(split[j], "/");
				path = ft_strjoin(path, cmd);
				if (access(path, F_OK | X_OK) == 0)//vérifier si le fichier existe et s'il est exécutable
				{
					free_tab(split);
					return (path);
				}
				free(path);
				j++;
			}
			free_tab(split);
		}
		i++;
	}
	return (NULL);
} */
void	ft_waitpid(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pipex->pid[i], NULL, 0);
		i++;
	}
}
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
