/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:14:38 by kammi             #+#    #+#             */
/*   Updated: 2023/11/17 16:14:05 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_dst;
	size_t	s_src;

	if ((!dst || !src) && (!size))
		return (0);
	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	j = s_dst;
	i = 0;
	if (s_dst < size - 1 && size > 0)
	{
		while (src[i] && s_dst + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (s_dst >= size)
		s_dst = size;
	return (s_dst + s_src);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "salut";
	char	dst[] = "cava";
	size_t	size = 10;

	printf("%zu | %s", ft_strlcat(dst, src, size), dst);
}
*/
