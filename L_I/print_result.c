/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:44:32 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/16 15:35:56 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_result(t_moove **moove, t_sum *s)
{
	t_moove	*m;
	t_ants	*a;
	t_room	*r;

	m = *moove;
	printf("\n");
	while (m)
	{
		a = m->ants;
//		printf("step %d\n", m->step_n);
		while (a)
		{
			r = s->room;
			while (r && r->n != a->room)
				r = r->next;
			printf("L%d-%s", a->ant_num, r->name);
			if (a->next != NULL)
				printf(" ");
			a = a->next;
		}
		printf("\n");
		m = m->next;
	}
}

void	print_init(t_sum *s)
{
	t_out	*o;

	o = s->final_output;
	while (o)
	{
		printf("%s\n", o->text);
		o = o->next;
	}
}

