/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:28:07 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/12 15:33:59 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lett(char const *s)
{
	int lett;
	int i;

	lett = 0;
	i = -1;
	while (s[++i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		;
	while (s[++i])
		lett++;
	while (s[--i] == ' ' || s[i] == '\n' || s[i] == '\t')
		lett--;
	return (lett + 1);
}

char		*ft_strtrim(char const *s)
{
	int		lett;
	int		i;
	int		j;
	char	*buff;

	if (!s)
		return (NULL);
	lett = ft_lett(s);
	if (!(buff = (char*)malloc(sizeof(char) * (lett + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		;
	while (j < lett)
	{
		buff[++j] = s[i];
		i++;
	}
	buff[j] = '\0';
	return (buff);
}
