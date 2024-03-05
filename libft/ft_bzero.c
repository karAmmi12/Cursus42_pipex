/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:45 by kammi             #+#    #+#             */
/*   Updated: 2023/11/21 16:40:45 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	array[] = { 5, 8, 75, 9, 24 };
	size_t	size;
	int	len;

	len = 0;
	size = sizeof( int ) * 5;

	while (len < 5)
	{
		printf("%d ", array[len]);
		len++;
	}
	printf("\n");
	bzero(array, size);
	len = 0;
	while (len < 5)
	{
		printf("%d ", array[len]);
		len++;
	}
	printf("\n");
	return 0;
}*/
