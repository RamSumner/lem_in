/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:15:06 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/10 13:27:59 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *buff;

	buff = malloc(size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size);
	return (buff);
}
