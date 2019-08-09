/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:05:57 by rsumner           #+#    #+#             */
/*   Updated: 2019/07/03 14:11:25 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_clean_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != NULL)
		ft_strdel(&tab[i]);
	tab = NULL;
	return (NULL);
}

static int		ft_words(const char *s, char c)
{
	int words;
	int i;

	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
	}
	return (words);
}

static char		*ft_fill(char const *s, char c, int i)
{
	char	*str;
	int		j;
	int		k;
	int		lett;

	k = i;
	lett = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		lett++;
	}
	if ((str = (char*)malloc(sizeof(char) * (lett + 1))))
	{
		j = 0;
		while (j < lett)
		{
			str[j] = s[k];
			k++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_words(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (words + 1))))
		return (NULL);
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[j] = ft_fill(s, c, i)))
			return (ft_clean_tab(tab));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
