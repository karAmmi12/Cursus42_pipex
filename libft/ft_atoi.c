/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:51:24 by kammi             #+#    #+#             */
/*   Updated: 2023/11/14 15:41:10 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	revert;
	int	value;

	revert = 1;
	value = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		revert *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (value * revert);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	str[] = " 214587";

	printf("%d\n", ft_atoi(str));
    printf("%d\n", atoi(str));
}
*/
