/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:09:27 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/12 17:41:14 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_clean_data(t_sum *s)
{
	t_room	*cur_r;
	t_room	*next_r;

	cur_r = s->room;
	while (cur_r)
	{
		next_r = cur_r->next;
		ft_strdel(&(cur_r->name));
		free(cur_r);
		cur_r = next_r;
	}
	s->room = NULL;
}

int ft_return(int status, t_sum *s)
{
	if (status == ERR)
		write(2, "error\n,", 6);
	ft_clean_data(s);
	return(status);
}

void print_s(t_sum *s)
{
	t_room *r_tmp;
	t_link *l;

	r_tmp = s->room;

	printf("number of ants = %d\n", s->n_ants);
	printf("number of rooms = %d\n", s->n_rooms);
	printf("number of links = %d\n", s->n_links);
	printf("starting room = %d\n", s->start);
	printf("finish room = %d\n", s->end);


	printf("---------the rooms---------\n");
	while (r_tmp)
	{
		printf("name: %s\n", r_tmp->name);
	//	printf("stat %d\n", r_tmp->stat);
		printf("n = %d\n", r_tmp->n);
		printf("x = %d, y = %d\n\n", r_tmp->x, r_tmp->y);
		r_tmp = r_tmp->next;
	}
	printf("---------the links---------\n");
	
	int i;
	i = 0;
	while (i < s->n_rooms)
	{
		printf("links for room %d: ", i);
		l = s->links[i];
		while (l)
		{
			printf("%d ", l->pair);
			if (l->next != NULL)
				printf("-> ");
			l = l->next;
		}
		printf("\n");
		i++;
	}
}

int main()
{
	t_sum	s;

	s.room = NULL;
	s.links = NULL;
	s.n_ants = 0;
	s.n_rooms = 0;
	s.n_links = 0;
	s.start = -1;
	s.end = -1;
	if (get_data(&s) == ERR || s.n_rooms < 2 || s.n_links < 1 || s.n_ants == 0)
		return(ft_return(ERR, &s));
	print_s(&s);
	if (find_solution(s) == ERR)
		return(ft_return(ERR, &s));
	return (ft_return(OK, &s));
}