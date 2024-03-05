/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:17:34 by kammi             #+#    #+#             */
/*   Updated: 2023/11/16 15:13:11 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		wlen;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab || !s)
		return (ft_free(tab, 0));
	j = 0;
	while (*s)
	{
		wlen = 0;
		while (*s && *s == c)
			s++;
		wlen = word_len(s, c);
		if (wlen)
		{
			tab[j] = ft_substr(s, 0, wlen);
			if (!tab[j])
				return (ft_free(tab, j));
			j++;
		}
		s += wlen;
	}
	tab[j] = 0;
	return (tab);
}
/*
#include <stdio.h>
int	main(void)i
{
	char	**tab;
	int	i;
	i= 0;
	tab = ft_split("salut comment vas tu", ' ');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
