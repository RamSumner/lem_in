/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:43:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/16 15:35:25 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_room_list(t_room **room)
{
	t_room	*tmp;
	t_room	*list;

	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		return (ERR);
	ft_bzero(tmp, sizeof(t_room));
	tmp->next = NULL;
	list = *room;
	tmp->next = list;
	*room = tmp;
	return (OK);
}

int		add_link_list(t_link **link)
{
	t_link	*tmp;
	t_link	*list;

	tmp = NULL;
	if (!(tmp = (t_link*)malloc(sizeof(t_link))))
		return (ERR);
	tmp->next = NULL;
	list = *link;
	tmp->next = list;
	*link= tmp;
	return (OK);
}

int	ft_add_to_queue(int step, int parent, int room_nb, t_queue **queue)
{
	t_queue *q;
	t_queue *new;

	q = *queue;
	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (ERR);
	new->room_nb = room_nb;
	new->step = step;
	new->parent = parent;
	new->next= NULL;
	new->prev = NULL;
	if (!*queue)
		new->stop = 0;
	else
		new->stop = q->stop;
	if (parent == room_nb)
		new->stop++;
	if (*queue)
	{
		while ((*queue)->next)
			(*queue) = (*queue)->next;
		(*queue)->next = new;
		new->prev = (*queue);
		(*queue) = q;
	}
	else
		(*queue) = new;
	return (OK);
}

t_moove *add_step(int step_n, t_moove **moove)
{
	t_moove *new;
	t_moove *m;
	t_moove *tmp;

	if (!(new = (t_moove*)malloc(sizeof(t_moove))))
		return (NULL);
	new->ants = NULL;
	new->step_n = step_n;
	new->next= NULL;
	m = *moove;
	if (!(*moove))
		*moove = new;
	else if (m->step_n > step_n)
	{
		new->next = m;
		*moove = new;
	}
	else
	{
		while (m)
		{
			if (m->next == NULL || (m->step_n < step_n && m->next->step_n > step_n))
			{
				tmp = m->next;
				m->next = new;
				new->next = tmp;
				break;
			}
			m = m->next;
		}
	}
	return (new);
}

int add_to_moove(int ant_num, int step_n, int room, t_moove **moove)
{
	t_moove *m;
	t_ants *new;
	t_ants *a;

	m = *moove;

	while (m && m->step_n != step_n)
		m = m->next;
	if (m == NULL && !(m = add_step(step_n, moove)))
		return (ERR);
	if (!(new = (t_ants*)malloc(sizeof(t_ants))))
		return (ERR);
	new->ant_num = ant_num;
	new->room = room;
	new->next= NULL;
	a = m->ants;
	if (m->ants == NULL)
		m->ants = new;
	else
	{
		while (a->next)
			a = a->next;
		a->next = new;
	}
	return (OK);
}