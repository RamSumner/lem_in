/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:51:03 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/09 15:54:22 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <sys/stat.h> 
#include <fcntl.h>

int add_room(t_sum *s, char **tab, int stat)
{
	int x;
	int y;

	if ((tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL) && tab[0][0] != 'L')
		return (3); /*maybe it's link */
	if (tab[0][0] == 'L' || get_nb(tab[1], &x, 'r') == ERR || get_nb(tab[2], &y, 'r') == ERR || find_name_num(tab[0], s->room) != ERR || add_room_list(&(s->room)) == ERR)
		return (ERR);
	if (!(s->room->name = ft_strdup(tab[0])))
		return (ERR);
	s->room->n = s->room->next == NULL ? 0 : s->room->next->n + 1;
	s->room->x = x;
	s->room->y = y;
	s->n_rooms++;
	if ((stat == 0 && s->start != -1) || (stat == 1 && s->end != -1))
		return (ERR);
	stat == 0 ? s->start = s->room->n : 0;
	stat == 1 ? s->end= s->room->n : 0;
	return (2);
}

int add_link(t_sum *s, char **tab)
{
	int n_a;
	int n_b;

	if (s->links == NULL && !(s->links = (t_link**)malloc(sizeof(t_link*) * s->n_rooms)))
		return (ERR);
	if (tab[0] == NULL || tab[1] == NULL || tab[2] != NULL)
		return (ERR);
	if ((n_a = find_name_num(tab[0], s->room)) == -1 || (n_b = find_name_num(tab[1], s->room)) == -1 || n_a == n_b || add_link_list(&(s->links[n_a])) == ERR || add_link_list(&(s->links[n_b])) == ERR)
		return (ERR);
	s->links[n_a]->pair = n_b;
	s->links[n_b]->pair = n_a;
	s->n_links++;
	return (3);
}

int add_data(char *str, t_sum *s, int type)
{
	char    **tab;
	int     stat;

	if (str[0] == '#' && str[1] != '#')
		return (type);
	else if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
			type = 0;
		else if (ft_strcmp(str, "##end") == 0)
			type = 1;
		else
			type = ERR;
	}
	else if (type < 3)
	{
		stat = type;
		if (!(tab = ft_strsplit(str, ' ')))
			return (ERR);
		if ((type = add_room(s, tab, stat)) == ERR)
			return(ERR);
		ft_clean_tab(tab);
	}
	if (type == 3)
	{
		if (!(tab = ft_strsplit(str, '-')))
			return (ERR);
		type = add_link(s, tab);
		ft_clean_tab(tab);
	}
	return (type);
}

int get_data(t_sum *s)
{
	int     ret;
	char    *line;
	int     type;

	int fd = open("test1.map", O_RDONLY); /*fd=0*/
	type = -1;
	line = NULL;
	ret = get_next_line(fd, &line); /* get num of ants */

	if (ret == ERR || get_nb(line, &(s->n_ants), 'a') == ERR || s->n_ants < 0)
	{
		ft_strdel(&line);
		get_next_line(-2, NULL);
		return (ERR);
	}
	while ((ret = get_next_line(fd, &line)) != OK && ret != ERR)
	{
		if ((type = add_data(line, s, type)) == ERR)
		{
			ft_strdel(&line);
			get_next_line(-2, NULL);
			return (ERR);
		}
		ft_strdel(&line);
	}
	return (ret);
}