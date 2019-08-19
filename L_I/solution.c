/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:21:20 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/19 16:02:47 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_queue(t_queue *queue)
{
	t_queue *q_curr;
	t_queue *q_next;

	q_curr = queue;
	while (q_curr)
	{
		q_next = q_curr->next;
		free(q_curr);
		q_curr = q_next;
	}
	queue = NULL;
}

int		ft_solut_return(int status, t_queue *queue, t_moove *moove)
{
	t_moove *m_curr;
	t_moove *m_next;
	t_ants *a_curr;
	t_ants *a_next;

	m_curr = moove;
	while (m_curr)
	{
		m_next = m_curr->next;
		a_curr = m_curr->ants;
		while (a_curr)
		{
			a_next = a_curr->next;
			free(a_curr);
			a_curr = a_next;
		}
		free(m_curr);
		m_curr = m_next;
	}
	moove = NULL;
	if (status == ERR)
		free_queue(queue);
	return(status);
}

void	ft_free_marks(int room_n, t_link **links)
{
	int		i;
	t_link	*l;
	
	i = -1;
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

int		find_solution(t_sum s)
{
	t_moove	*moove;
	t_queue *queue;
	int		i;

	moove = NULL;
	queue = NULL;
	i = -1;
	while (++i < s.n_ants)
	{
		ft_free_marks(s.n_rooms, s.links);
		if (find_path(i + 1, &s, &queue, &moove) == ERR)
			return (ft_solut_return(ERR, queue, moove));
		free_queue(queue);
		queue = NULL;
	}
	print_init(&s);
	print_result(&moove, &s);
	return (ft_solut_return(OK, queue, moove));
}
