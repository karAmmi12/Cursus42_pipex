/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:38:08 by kammi             #+#    #+#             */
/*   Updated: 2023/11/21 16:39:33 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (size != 0 && nmemb > (size_t) - 1 / size)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (nmemb * size));
	return (tmp);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{

	printf("%p\n", ft_calloc(9999, 1000));
	printf("%p\n", calloc(9999, 1000));
	return (0);
}
*/
