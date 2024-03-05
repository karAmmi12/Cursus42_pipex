/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:29:20 by kammi             #+#    #+#             */
/*   Updated: 2023/11/21 14:51:16 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1 && s1[i])
	{
		dst[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		dst[j++] = s2[i];
		i++;
	}
	dst[j] = 0;
	return (dst);
}
/*
#include <stdio.h>
int     main(void)
{
    printf("%s\n", ft_strjoin("salut", "Mister"));
}*/
