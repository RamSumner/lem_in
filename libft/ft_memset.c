/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:50:18 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/08 11:00:24 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*dest;
	int				i;

	value = (unsigned char)c;
	dest = (unsigned char *)b;
	i = 0;
	while (len != 0)
	{
		dest[i] = value;
		i++;
		len--;
	}
	return (b);
}
