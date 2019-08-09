/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:17:14 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/10 16:48:31 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	buff = ft_strnew(len);
	if (buff && s)
	{
		while (len > 0)
		{
			buff[i] = s[start + i];
			i++;
			len--;
		}
	}
	return (buff);
}
