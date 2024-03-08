/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:36:31 by kammi             #+#    #+#             */
/*   Updated: 2024/03/08 17:46:44 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_redirect(t_pipex *pipex, int i)
{
	if (i != 0)
	{
		dup2(pipex->prev_fd, 0);
		close(pipex->prev_fd);
	}
	if (i != pipex->cmd_count - 1)
		dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	ft_waitpid(t_pipex *pipex)
{
	int	i;
	int	status;
	int	*exit_status;

	exit_status = malloc(pipex->cmd_count * sizeof(int));
	if (!exit_status)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (-1);
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pipex->pid[i], &status, 0);
		exit_status[i] = status >> 8;
		i++;
	}
	status = exit_status[pipex->cmd_count - 1];
	free(exit_status);
	return (status);
}

void	open_input_file(t_pipex *pipex)
{
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	if (pipex->fd_in < 0)
	{
		perror(pipex->infile);
		exit(0);
	}
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_in);
}

void	open_output_file(t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->fd_out = open(pipex->outfile,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->fd_out = open(pipex->outfile,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
	{
		perror(pipex->outfile);
		exit(1);
	}
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_out);
}

void	ft_open_file(t_pipex *pipex, int i)
{
	if (i == 0)
		open_input_file(pipex);
	else if (i == pipex->cmd_count - 1)
		open_output_file(pipex);
}