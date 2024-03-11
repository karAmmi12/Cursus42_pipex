/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:37:57 by kammi             #+#    #+#             */
/*   Updated: 2024/03/11 18:00:09 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	read_and_write(int fd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, 0);
		if (!line)
		{
			free(line);
			break ;
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& (ft_strlen(line) - 1) == ft_strlen(limiter))
		{
			free(line);
			get_next_line(0, 1);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
}

void	ft_here_doc(t_pipex *pipex, char *limiter)
{
	int		fd;

	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error: here_doc\n", 2);
		return ;
	}
	read_and_write(fd, limiter);
	close(fd);
	pipex->infile = "here_doc";
}
