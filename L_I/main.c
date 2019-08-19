/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:27:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/19 15:40:32 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clean_links(t_sum *s)
{
	t_link	*cur_l;
	t_link	*next_l;
	int i;

	i = -1;
	while (++i < s->n_rooms)
	{
		cur_l = s->links[i];
		while (cur_l)
		{
			next_l = cur_l->next;
			free(cur_l);
			cur_l = next_l;
		}
	}
	free(s->links);
}

void	ft_clean_out(t_sum *s)
{
	t_out	*cur_o;
	t_out	*next_o;

	cur_o = s->final_output;
	while (cur_o)
	{
		next_o = cur_o->next;
		ft_strdel(&(cur_o->text));
		free(cur_o);
		cur_o = next_o;
	}
}

int		ft_return_main(int status, t_sum *s)
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
	if (s->n_links)
		ft_clean_links(s);
	ft_clean_out(s);
	if (status == ERR)
		write(1, "ERROR\n", 6);
	return (0);
}

t_sum	create_new_sum_structure(void)
{
	t_sum	s;

	s.room = NULL;
	s.links = NULL;
	s.n_ants = 0;
	s.n_rooms = 0;
	s.n_links = 0;
	s.start = -1;
	s.end = -1;
	s.final_output = NULL;
	s.dir = 0;
	return (s);
}

int		main()
{
	t_sum	s;

	s = create_new_sum_structure();
	if (get_data(&s) == ERR || s.n_rooms < 2 || s.n_links < 1 || s.n_ants == 0\
	|| s.end == -1 || s.start == -1)
		return(ft_return_main(ERR, &s));
	if (find_solution(s) == ERR)
		return (ft_return_main(ERR, &s));
	return (ft_return_main(OK, &s));
}
