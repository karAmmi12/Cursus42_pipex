/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:11:50 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 14:27:28 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	int	array[] = { 5, 8, 5, 55, 33};
	int	i;
	size_t	size;

	i = 0;
	size = sizeof( int ) * 4;

	while (len < 5)
	{
		printf("%d ", array[len]);
		i++;
	}
	printf("\n");
	ft_memset(array, 0, size);
	len = 0;
	while (len < 5)
	{
		printf("%d ", array[len]);
		i++;
	}
	printf("\n");
	return 0;
}*/
