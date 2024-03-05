/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:28:49 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 15:49:04 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int     main(void)
{
        const char s[] = "merci";
        char    c;
	size_t	n;
        const char *result;

        c = 'c';
	n = 4;
        result = memchr(s, c, n);
        if (result != NULL)
                printf("%c trouve a l'adresse : %p\n", c, result);
        else
                printf("%c non trouve\n", c);
}
*/