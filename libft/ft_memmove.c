/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:04:10 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/09 12:13:58 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstn;
	unsigned const char	*srcn;

	if (len == 0 || dst == src)
		return (dst);
	dstn = dst;
	srcn = src;
	if (src > dst)
	{
		while (len > 0)
		{
			*dstn++ = *srcn++;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*(dstn + len - 1) = *(srcn + len - 1);
			len--;
		}
	}
	return (dst);
}
