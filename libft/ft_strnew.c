/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:50:34 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/24 10:58:53 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *buff;

	buff = NULL;
	if (((size + 1) - 1) == size)
		buff = (char *)malloc(size + 1);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size + 1);
	return (buff);
}
