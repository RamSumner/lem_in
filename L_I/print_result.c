/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:44:32 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/20 14:37:29 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_init(t_sum *s)
{
	t_out	*o;

	o = s->final_output;
	while (o)
	{
		ft_printf("%s\n", o->text);
		o = o->next;
	}
}

void	print_result(t_moove **moove, t_sum *s)
{
	t_moove	*m;
	t_ants	*a;
	t_room	*r;

	print_init(s);
	m = *moove;
	ft_printf("\n");
	while (m)
	{
		a = m->ants;
		while (a)
		{
			r = s->room;
			while (r && r->n != a->room)
				r = r->next;
			ft_printf("L%d-%s", a->ant_num, r->name);
			if (a->next != NULL)
				ft_printf(" ");
			a = a->next;
		}
		ft_printf("\n");
		m = m->next;
	}
}
