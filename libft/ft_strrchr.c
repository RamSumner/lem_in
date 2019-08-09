/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:44:34 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/09 15:47:13 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int p;

	i = 0;
	p = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)(s + i));
	if (p != -1)
		return ((char*)(s + p));
	return (NULL);
}
