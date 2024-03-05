/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:24:02 by kammi             #+#    #+#             */
/*   Updated: 2024/02/13 17:07:51 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[j++] = s1[i++];
	}
	if (s1)
		free(s1);
	i = 0;
	while (s2 && s2[i])
	{
		dest[j++] = s2[i++];
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strcpy_gnl(char *dest, char *src, int nls)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (nls && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
