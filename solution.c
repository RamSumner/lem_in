/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:21:20 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/09 18:03:25 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_return_2(int status, t_moove *moove)
{
	if (status == ERR)
		write(2, "error\n,", 6);
//	ft_clean_data(s);
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

int find_path(t_sum *s, t_moove **moove)
{
    int *checked;
    t_link *queue;

    checked = (int*)malloc(sizeof(int) * s->n_rooms);
    ft_bzero(checked, s->n_rooms);
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
        if (find_path(&s, &moove) == ERR)
            return (ft_return_2(ERR, moove));
    }
    print_moove(moove);
    return (ft_return_2(OK, moove));
}