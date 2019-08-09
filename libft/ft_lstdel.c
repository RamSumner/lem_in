/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:59:32 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/15 13:23:50 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_cur;
	t_list	*tmp_next;

	if (del)
	{
		tmp_cur = *alst;
		while (tmp_cur)
		{
			tmp_next = tmp_cur->next;
			del(tmp_cur->content, tmp_cur->content_size);
			free(tmp_cur);
			tmp_cur = tmp_next;
		}
		*alst = NULL;
	}
}
