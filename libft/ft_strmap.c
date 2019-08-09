/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:06 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/15 15:25:30 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buff;
	int		i;

	i = -1;
	if (s)
	{
		buff = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (buff && f)
		{
			while (s[++i])
				buff[i] = f(s[i]);
			buff[i] = '\0';
			return (buff);
		}
	}
	return (0);
}
