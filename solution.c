/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:21:20 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/12 17:46:39 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_return_2(int status, t_moove *moove)
{
	if (status == ERR)
		write(2, "error\n,", 6);
//	ft_clean_data(s);
	moove = NULL; /* tmp */
	return(status);
}

void    print_moove(t_moove *moove)
{
	t_moove *m;
	t_step  *s;

	m = moove;
	while (m)
	{
		printf("\n----step № %d:----\n", m->step_n);
		s = m->step;
		while (s)
		{
			printf("ant_num %d: ", s->ant_num);
			printf("from %d to %d\n", s->from, s->dest);
			s = s->next;
		}
		m = m->next;
	}
}

void ft_free_marks(int room_n, t_link **links)
{
	int i;
	i = -1;
	t_link *l;

	while (++i < room_n)
	{
		l = links[i];
		while (l)
		{
			l->mark = 0;
			l = l->next;
		}
	}
}

int	ft_add_to_queue(int step, int parent, int room_nb, t_queue **queue) /* need to create the full copy */
{
	t_queue *q;
	t_queue *new;

	q = *queue;
	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (ERR);
	new->room_nb = room_nb;
	new->step = step;
	new->parent = parent;
	new->next= NULL;
	if (q)
	{
		while (q->next)
			q = q->next;
		q->next = new;
	}
	else
		q = new;
	new->prev = q;
	return (OK);
}

int find_path(t_sum *s, t_moove **moove) /* add checking for solution existance */
{
	t_queue *queue;
	t_queue *start_q;
	t_link *l;
	t_moove *m;
	int		step;

	m = *moove;
	step = 1;
	queue = NULL;
	ft_add_to_queue(0, s->start, s->links[s->start]->pair, &queue); /* add start room in the queue */
	start_q = queue;
	while (queue && queue->room_nb != s->end)
	{
		l = s->links[queue->room_nb];
		while (l)
		{
			ft_add_to_queue(step, queue->room_nb, l->pair, &queue);
			l = l->next;
		}
		step++;
		queue = queue->next;
	}

	while(start_q) /*checking */
	{
		printf("tot queue\n");
		printf("room_nb = %d, step = %d, parent = %d\n", start_q->room_nb, start_q->step, start_q->parent);
		start_q = start_q->next;
	}
//	printf("finish\nroom_nb = %d, step = %d, parent = %d\n", queue->room_nb, queue->step, queue->parent);
	return (OK);
}

int find_solution(t_sum s)
{
	t_moove     *moove;
	int i;

	moove = NULL;

	
	i = -1;
	while (++i < s.n_ants)
	{
		ft_free_marks(s.n_rooms, s.links); /* zero checking marks in all links before new ant */
		if (find_path(&s, &moove) == ERR)
			return (ft_return_2(ERR, moove));
	}
	print_moove(moove);
	return (ft_return_2(OK, moove));
}