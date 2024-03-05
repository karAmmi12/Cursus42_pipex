/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:26 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 13:17:17 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (unsigned char)s1[i]
		&& (unsigned char)s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char	s1[] = "toto";
	char	s2[] = "totu";
	size_t	n = 5i;
	int	r = ft_strncmp(s1, s2, n);

	if ( r < 0)
		 printf(" les %ld premiers caracteres 
		 de %s sont inferieurs a ceux de %s\n",n, s1, s2);
	else if (r > 0)
		printf(" les %ld premiers caracteres 
		de %s sont superieurs a ceux de %s\n",n, s1, s2);
	else
		printf(" les %ld premiers caracteres 
		de %s sont  identiques a ceux de %s\n", n, s1, s2);
}
*/
