/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_solut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:51:30 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/19 14:15:28 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int if_room_checked(t_link	*links)
{
	t_link	*l;

	l = links;
	while (l)
	{
		if (l->mark == 1)
			return (1);
		l = l->next;
	}
	return (0);
}

int if_room_free(int step, int room, t_moove **moove)
{
	t_moove *m;
	t_ants *a;

	m = *moove;
	while (m)
	{
		if (m->step_n == step)
		{
			a = m->ants;
			while (a)
			{
				if (a->room == room)
					return (1);
				a = a->next;
			}
		}
		m = m->next;
	}
	return (0);
}

int if_in_queue(int step, int parent, int room_nb, t_queue **queue)
{
	t_queue *q;

	q = *queue;
	while (q)
	{
		if (q->parent == parent && q->room_nb == room_nb && q->step == step)
			return (1);
		q = q->next;
	}
	return (0);
}