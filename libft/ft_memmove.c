/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:12:51 by kammi             #+#    #+#             */
/*   Updated: 2023/11/20 13:05:26 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*t_dest;
	char	*t_src;

	if (!src && !dest)
		return (NULL);
	i = 0;
	t_src = (char *)src;
	t_dest = (char *)dest;
	if (dest > src)
	{
		while (n-- > 0)
			t_dest[n] = t_src[n];
	}
	else
	{
		while (i < n)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char src[] = "coucou";
	char dest[] = "salut";
	ft_memmove(dest, src, 5);
	printf("%s",dest);
	return (0);
}*/
