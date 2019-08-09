/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:08:28 by rsumner           #+#    #+#             */
/*   Updated: 2019/07/11 15:28:19 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_clean_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != NULL)
		ft_strdel(&tab[i]);
	free(tab);
	return (NULL);
}

int ft_find_lett(char *s, int i, char c)
{
	int lett;

	lett = 0;
	while (s[i])
	{	
		
		if (i > 0 && s[i] == c && s[i-1] != c && (s[i + 1] != c || s[i + 1] == '\0'))
			break ;
		i++;
		lett++;		
		
		
	}
	return (lett);
}

static int	ft_fill(char *s, char c, char **tab)
{
	int	i;
	int	j;
	int k;
	int lett;
	
	i = -1;
	k = -1;
	lett = 1;
	while (++i < 3)
	{
		lett = ft_find_lett(s, k + 1, c);
		if (lett == 0)
			break ;
		if (!(tab[i]= (char*)malloc(sizeof(char) * (lett + 1))))
			return (ERR);
		j = -1;
		while (++j < lett)
			tab[i][j] = s[++k];
		tab[i][j] = '\0';
		k = k+1;
	}
	tab[i] = NULL;
	return (OK);
}

char			**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) * 4)) || ft_fill(s, c, tab) == ERR)
		return (NULL);
	return (tab);
}
