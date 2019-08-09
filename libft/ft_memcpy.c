/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:52:01 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/15 12:40:07 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstn;
	unsigned const char	*srcn;

	dstn = (unsigned char*)dst;
	srcn = (unsigned const char*)src;
	i = 0;
	while (n > 0)
	{
		dstn[i] = srcn[i];
		i++;
		n--;
	}
	return (dst);
}
