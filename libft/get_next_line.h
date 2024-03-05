/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:23:54 by kammi             #+#    #+#             */
/*   Updated: 2024/02/23 14:43:17 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd, int error);
char	*ft_fill(int fd, char *data);
char	*ft_extract_line(char *data);
char	*ft_update_data(char *old_data);
size_t	ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strcpy_gnl(char *dest, char *src, int nls);

#endif
