/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:27:59 by kammi             #+#    #+#             */
/*   Updated: 2024/03/08 13:40:04 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_init_pipex(t_pipex *pipex, char **av, char **envp, int ac)
{
	if (pipex->here_doc)
	{
		pipex->cmd_count = ac - 4;
		pipex->cmd = &av[3];
	}
	else
	{
		pipex->cmd_count = ac - 3;
		pipex->cmd = &av[2];
	}
	pipex->envp = envp;
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
}

char	*ft_find_path(char **split, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], "/");
		tmp = path;
		path = ft_strjoin(tmp, cmd);
		free(tmp);
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	cleanup_pipex(t_pipex *pipex)
{
	free(pipex->pid);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (pipex->here_doc)
		unlink("here_doc");
}
