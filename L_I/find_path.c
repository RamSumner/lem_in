/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:41:45 by rsumner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/16 16:57:06 by rsumner          ###   ########.fr       */
=======
/*   Updated: 2019/08/16 12:41:34 by rsumner          ###   ########.fr       */
>>>>>>> rsumner
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue *best_way(int step, int room, t_queue *q)
{
	t_queue *tmp;
	t_queue *best;
	int best_step;
	
	tmp = q;
	best = q;
	best_step = tmp->step - tmp->stop;
	while (tmp && tmp->step == step)
	{
		if (tmp->room_nb == room && tmp->step - tmp->stop < best_step)
		{
			best_step = tmp->step - tmp->stop;
			best = tmp;
		}
		tmp = tmp->prev;
	}
	return (best);
}



int	fill_moove(int ant_num, t_queue *q, t_moove **moove)
{
	int	par;
	int	step;

	if (add_to_moove(ant_num, q->step, q->room_nb, moove) == ERR)
		return (ERR);
	par = q->parent;
	step = q->step;
	while (q && q->step != 0)
	{
		if (q->room_nb == par && q->step == step - 1)
		{
			q = best_way(q->step, q->room_nb, q);
			if (q->room_nb != q->parent)
			{
				if (add_to_moove(ant_num, q->step, q->room_nb, moove) == ERR)
					return (ERR);
				par = q->parent;
				step = q->step;
			}
			if (q->room_nb == q->parent)
				step--;
		}
		q = q->prev;
	}
	return (OK);
}

int	find_path_2(t_sum *s, t_queue *start_q, t_queue *q, t_moove **moove)
{
	t_link	*l;
	t_queue	*queue;
	int		free;

	queue = q;
	free = 0;
	l = s->links[queue->room_nb];
	while (l)
	{
		if (l->pair == s->end)
		{
			if (s->dir == 0 || (s->dir == 1 && queue->room_nb == s->start && (free = if_room_free(queue->step + 1, l->pair, moove)) == 0))
			{
				if (ft_add_to_queue(queue->step + 1, queue->room_nb, l->pair, &queue) == ERR)
					return (ERR);
				l->mark = 1;
			}
		}
		if ((if_room_cheched(s->links[l->pair]) == 0 &&
			(free = if_room_free(queue->step + 1, l->pair, moove)) == 0 &&
			if_in_queue(queue->step + 1, queue->room_nb, l->pair, &start_q) == 0))
		{
			if (ft_add_to_queue(queue->step + 1, queue->room_nb, l->pair, &queue) == ERR)
				return (ERR);
			l->mark = 1;
		}
		if (free == 1 && if_in_queue(queue->step + 1, queue->room_nb,
			queue->room_nb, &start_q) == 0 && ft_add_to_queue(queue->step + 1,
			queue->room_nb, queue->room_nb, &queue) == ERR)
			return (ERR);
		l = l->next;
	}
	return (OK);
}

t_queue *best_solution(int step, int end, t_queue *queue)
{
	t_queue *tmp;
	t_queue *best;
	int best_step;

	tmp = queue;
	best = queue;
	
	best_step = tmp->step - tmp->stop;
	while (tmp && tmp->step == step)
	{
		if (tmp->room_nb == end && tmp->step - tmp->stop < best_step)
		{
			best_step = tmp->step - tmp->stop;
			best = tmp;
		}
		tmp = tmp->next;
	}
	return (best);
}

int find_path(int ant_num, t_sum *s, t_queue **q, t_moove **moove)
{
	t_queue *queue;
	t_queue *start_q;

	queue = *q;
	if (ft_add_to_queue(0, -1, s->start, &queue) == ERR)
		return (ERR);
	start_q = queue;
	while (queue && queue->room_nb != s->end)
	{
		if (find_path_2(s, start_q, queue, moove) == ERR)
			return (ERR);
		queue = queue->next;
	}
	if (!queue)
		return (ERR);

//	printf("-----------Queue----------\n");
//	while(start_q) /*checking */
//	{
//		printf("room_nb = %d, step = %d, parent = %d\n", start_q->room_nb, start_q->step, start_q->parent);
//		start_q = start_q->next;
//	}
//	printf("finish\nroom_nb = %d, step = %d, parent = %d\n", queue->room_nb, queue->step, queue->parent);
	
	queue = best_solution(queue->step, s->end, queue);
	if (fill_moove(ant_num, queue, moove) == ERR)
		return (ERR);
	*q = start_q;
	return (OK);
}
