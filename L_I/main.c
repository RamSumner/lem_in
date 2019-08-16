/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:09:27 by rsumner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/16 17:36:33 by rsumner          ###   ########.fr       */
=======
/*   Updated: 2019/08/16 15:39:07 by rsumner          ###   ########.fr       */
>>>>>>> rsumner
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_sum	s;

	s = create_new_sum_structure();
	if (get_data(&s) == ERR || s.n_rooms < 2 || s.n_links < 1 || s.n_ants == 0)
		return(ft_return_main(ERR, &s));
	if (s.end == -1 || s.start == -1)
		return (ft_return_main(ERR, &s));
	if (find_solution(s) == ERR)
		return (ft_return_main(ERR, &s));
	return (ft_return_main(OK, &s));
}
