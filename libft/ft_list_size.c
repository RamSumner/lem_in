/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:33:39 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/15 11:35:34 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	size_t		i;

	i = 0;
	if (begin_list)
	{
		while (begin_list)
		{
			i++;
			begin_list = begin_list->next;
		}
		return (i);
	}
	return (0);
}
