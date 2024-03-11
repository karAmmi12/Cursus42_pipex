/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:37:32 by kammi             #+#    #+#             */
/*   Updated: 2024/03/11 16:50:48 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>

typedef struct s_pipex
{
	int		fd[2];
	int		cmd_count;
	int		*pid;
	int		prev_fd;
	char	**cmd;
	char	**envp;
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;

}	t_pipex;

void	ft_init_pipex(t_pipex *pipex, char **av, char **envp, int ac);
int		ft_pipex(t_pipex *pipex);
void	handle_child_process(t_pipex *pipex, int i);
void	ft_redirect(t_pipex *pipex, int i);
void	ft_open_file(t_pipex *pipex, int i);
void	ft_execve(t_pipex *pipex, char *cmd);
void	handle_execve_error(void);
char	*ft_get_path(char **envp, char *cmd);
char	*ft_find_path(char **split, char *cmd);
int		ft_waitpid(t_pipex *pipex);
void	free_tab(char **tab);

#endif
