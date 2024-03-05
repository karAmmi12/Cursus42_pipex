/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:28:37 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 16:01:26 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int     main(void)
{
        const char s[] = "bonjour";
        char    c;
        const char *result;

        c = 'n';
        result = ft_strrchr(s, c);
        if (result != NULL)
                printf("'%c' trouve a l'index : %ld\n", c, result - s);
        else
                printf("'%c' non trouve", c);
}*/
