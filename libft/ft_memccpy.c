/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:56:07 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/24 13:16:56 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,\
		size_t n)
{
	unsigned char		*dstn;
	unsigned const char	*srcn;
	int					i;

	dstn = dst;
	srcn = src;
	i = 0;
	while (n > 0 && srcn[i] != (unsigned char)c)
	{
		dstn[i] = srcn[i];
		i++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
	{
		dstn[i] = srcn[i];
		return (dst + i + 1);
	}
}
