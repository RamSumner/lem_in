/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:51:02 by rsumner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/16 17:05:59 by rsumner          ###   ########.fr       */
=======
/*   Updated: 2019/08/16 10:45:13 by rsumner          ###   ########.fr       */
>>>>>>> rsumner
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_return_get(char **line)
{
	ft_strdel(line);
	get_next_line(-2, NULL);
	return (ERR);
}

int	ft_int(char *str, int min)
{
	int		i;
	char	*int_p;
	char	*int_n;

	int_p = "2147483647";
	int_n = "2147483648";
	i = 0;
	while (str[i] && min == 1)
	{
		if (str[i] > int_p[i])
			return (ERR);
		i++;
	}
	while (str[i] && min == -1)
	{
		if (str[i] > int_n[i])
			return (ERR);
		i++;
	}
	return (OK);
}

int	get_nb(char *str, int *nb, int type)
{
	int i;
	int m;
	int l;

	i = 0;
	m = 1;
	m = str[i] == '-' ? -1 : 1;
	*nb = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 0)
		return (ERR);
	if ((l = ft_strlen(&str[i])) > 10 || (l == 10 && ft_int(&str[i], m) == ERR))
		return (ERR);
	i--;
	while (str[++i] >= '0' && str[i] <= '9' && str[i] != '\0')
		*nb = (*nb * 10) + (str[i] - '0');
	if (str[i] != '\0' && type == 'a') /* for ants num */
		return (ERR);
	*nb = (*nb) * m;
	return (OK);
}

int find_name_num(char *str, t_room *r)
{
	t_room *tmp;

	tmp = r;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (tmp->n);
		tmp = tmp->next;
	}
	return (ERR);
}

int	check_for_same_coor(t_sum *s)
{
	t_room	*curr;

	if (s->n_rooms <= 1)
		return (OK);
	curr = s->room->next;
	while (curr)
	{
		if (s->room->x == curr->x && s->room->y == curr->y)
			return (ERR);
		curr = curr->next;
	}
	return (OK);
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
<<<<<<< HEAD
=======
//	sleep (3); /* tmp*/
>>>>>>> rsumner
	if (status == ERR)
		write(1, "ERROR\n", 6);
	return (0);
}

void	ft_clean_out(t_sum *s)
{
	t_out	*cur_o;
	t_out	*next_o;

	cur_o = s->final_output;
	while (cur_o)
	{
		next_o = cur_o->next;
	//	ft_strdel(&(cur_o->text));
		free(cur_o);
		cur_o = next_o;
	}
}

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
