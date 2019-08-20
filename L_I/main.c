/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:27:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/20 14:48:56 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_sum	s;

	s = create_new_sum_structure();
	if (get_data(&s) == ERR || s.n_rooms < 2 || s.n_links < 1 || s.n_ants == 0\
	|| s.end == -1 || s.start == -1)
		return (ft_return_main(ERR, &s));
	if (find_solution(s) == ERR)
		return (ft_return_main(ERR, &s));
	return (ft_return_main(OK, &s));
}
