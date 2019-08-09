/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:51:24 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/15 11:51:30 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	n;
	t_list			*temp;

	temp = begin_list;
	n = 0;
	if (temp)
	{
		while (n < nbr - 1)
		{
			temp = temp->next;
			n++;
		}
		return (temp);
	}
	return (0);
}
