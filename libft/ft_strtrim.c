/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:37:18 by kammi             #+#    #+#             */
/*   Updated: 2023/11/21 14:42:52 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dest;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (ft_char_in_set(s1[end - 1], set) && start < end)
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[start] && start < end)
	{
		dest[i] = s1[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strtrim("ababababaaabKarimabaaabba","ab"));
}
*/
