/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:14:09 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 16:10:12 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        const char s1[] = "bonjour";
	const char s2[] = "bonbon";
	size_t  n;

        n = 3;
        printf("%d\n" , ft_memcmp(s1, s2, n));
        printf("%d\n" , memcmp(s1, s2, n));
}*/
