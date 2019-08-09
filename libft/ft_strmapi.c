/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:51:35 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/12 18:51:42 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				buff[i] = f(i, s[i]);
			buff[i] = '\0';
			return (buff);
		}
	}
	return (0);
}
