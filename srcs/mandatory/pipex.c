/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:38:02 by kammi             #+#    #+#             */
/*   Updated: 2024/03/11 18:10:11 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_execve_error(void)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("Error: no such file or directory\n", 2);
		exit(127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("Error: permission denied\n", 2);
		exit(126);
	}
	else
		exit(1);
}

void	ft_execve(t_pipex *pipex, char *cmd)
{
	char	**split;

	split = ft_split(cmd, ' ');
	if (!split)
		return ;
	cmd = ft_get_path(pipex->envp, split[0]);
	if (cmd)
	{
		execve(cmd, split, pipex->envp);
		free_tab(split);
		free(cmd);
		handle_execve_error();
	}
	else
	{
		ft_putstr_fd("Error: command not found\n", 2);
		free_tab(split);
		exit(127);
	}
}

void	handle_child_process(t_pipex *pipex, int i)
{
	free(pipex->pid);
	ft_redirect(pipex, i);
	if (i == 0 || i == pipex->cmd_count - 1)
		ft_open_file(pipex, i);
	ft_execve(pipex, pipex->cmd[i]);
	free(pipex->pid);
	exit(127);
}

int	ft_pipex(t_pipex *pipex)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < pipex->cmd_count)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
			exit(1);
		if (pipex->pid[i] == 0)
			handle_child_process(pipex, i);
		else
		{
			close(pipex->fd[1]);
			if (i > 0)
				close(pipex->prev_fd);
			pipex->prev_fd = pipex->fd[0];
		}
		i++;
	}
	ret = ft_waitpid(pipex);
	return (ret);
}

int	main(int ac, char **av, char **envp)
{
	static t_pipex	pipex = {0};
	int				ret;

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
	ret = ft_pipex(&pipex);
	free(pipex.pid);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	return (ret);
}
