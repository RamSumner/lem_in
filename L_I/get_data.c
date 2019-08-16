/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:51:03 by rsumner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/16 19:22:24 by rsumner          ###   ########.fr       */
=======
/*   Updated: 2019/08/16 15:35:56 by rsumner          ###   ########.fr       */
>>>>>>> rsumner
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <sys/stat.h>
#include <fcntl.h>

int	add_room(t_sum *s, char **tab, int stat)
{
	int x;
	int y;

	if (!tab || !*tab)
		return (ERR);
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
	if (check_for_same_coor(s) == ERR)
		return (ERR);
	if ((stat == 0 && s->start != -1) || (stat == 1 && s->end != -1))
		return (ERR);
	stat == 0 ? s->start = s->room->n : 0;
	stat == 1 ? s->end = s->room->n : 0;
	return (2);
}

char	*ft_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*a;

	if (!s1)
	{
		a = ft_strdup(s2);
		return (a);
	}
	if (!(a = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		a[i] = s1[i];
	a[i] = '-';
	while (s2[++j])
		a[i + j + 1] = s2[j];
	a[i + j + 1] = '\0';
	return (a);
}

int is_complex_name(char **tab, t_sum *s)
{
	char *a;
	char *b;
	int i;
	int j;

	a = NULL;
	b = NULL;

	i = 0;
	j = 1;
	while (tab[j])
	{
		while (tab[i] && i < j)
		{
			a = ft_join(a, tab[i]);
			i++;
		}
		while (tab[j])
		{
			b = ft_join(b, tab[j]);
			j++;
		}
		if (find_name_num(a, s->room) != -1 && find_name_num(b, s->room) != -1)
		{
			tab[0] = a;
			tab[1] = b;
			tab[2] = NULL;
			
			printf("%s <--> %s\n", tab[0], tab[1]);
			return (1);
		}
		else
		{
			j = i + 1;
			i = 0;
			ft_strdel(&a);
			ft_strdel(&b);
		}
			
	}
	return (0); /*name is simple*/
}

int	add_link(t_sum *s, char **tab)
{
	int n_a;
	int n_b;
	t_link *tmp;

	if (!s->links)
	{
		if (!(s->links = (t_link **)malloc(sizeof(t_link *) * s->n_rooms)))
			return (ERR);
		ft_bzero(s->links, sizeof(t_link *) * s->n_rooms);
	}
	if ((tab[0] == NULL || tab[1] == NULL || tab[2] != NULL) && (tab[0] != NULL && tab[1] != NULL && tab[2] != NULL && is_complex_name(tab, s) == 0))
		return (STOP);
	if ((n_a = find_name_num(tab[0], s->room)) == -1 || (n_b = find_name_num(tab[1], s->room)) == -1 || n_a == n_b)
		return (STOP);
	tmp = s->links[n_a];
	while (tmp)
	{
		if (tmp->pair == n_b)
			return (STOP);
		tmp = tmp->next;
	}
	if (add_link_list(&(s->links[n_a])) == ERR || add_link_list(&(s->links[n_b])) == ERR)
		return (ERR);
	s->links[n_a]->pair = n_b;
	s->links[n_b]->pair = n_a;
	s->n_links++;
	if ((n_a == s->start && n_b == s->end) || (n_b == s->start && n_a == s->end))
		s->dir = 1;
	return (3);
}

int	add_data_2(char *str, t_sum *s, int type)
{
	char	**tab;
	int		stat;

	if (type < 3)
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
		if ((type = add_link(s, tab)) == STOP || type == ERR)
			return (type);
		ft_clean_tab(tab);
	}
	return (type);
}

int	add_data(char *str, t_sum *s, int type)
{
	if (str[0] == '#' && str[1] != '#')
		return (2);
	if (str[0] == '#' && str[1] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
		{
			if (s->start < 0)
				type = 0;
			else
				type = STOP;
		}
		else if (ft_strcmp(str, "##end") == 0)
		{
			if (s->end < 0)
				type = 1;
			else
				type = STOP;
		}
		else
			return(type);
	}
	else
		return(add_data_2(str, s, type));
	return (type);
}

int add_to_output(char **line, t_out **out)
{
	t_out *o;
	t_out *new;

	o = *out;
	if (!(new = (t_out *)malloc(sizeof(t_out))))
		return (ERR);
	new->text = *line;
	new->next= NULL;
	if (!*out)
		*out = new;
	else
	{
		while ((*out)->next)
			(*out) = (*out)->next;
		(*out)->next = new;
		*out = o;
	}
	return (OK);
}

int	get_data(t_sum *s)
{
	int		ret;
	char	*line;
	int		type;

	type = -1;
	line = NULL;
//	int fd = open("test1.map", O_RDONLY); /* tmp */
	
	while (s->n_ants == 0)
	{
		if (!(ret = get_next_line(0, &line)))
			return (ERR);
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			return (ERR);
		if ((line[0] != '#' && get_nb(line, &(s->n_ants), 'a') == ERR) || s->n_ants < 0)
			return (ft_return_get(&line));
		if (((line[0] != '#' && s->n_ants > 0 ) || line[0] == '#') && add_to_output(&line, &(s->final_output)) == ERR)
			return (ft_return_get(&line));
	//	ft_strdel(&line);
		line = NULL;
	}
	while ((ret = get_next_line(0, &line)) != OK && ret != ERR && type != STOP)
	{
		if ((type = add_data(line, s, type)) == ERR)
			return (ft_return_get(&line));
		if (type != STOP && add_to_output(&line, &(s->final_output)) == ERR)
			return (ft_return_get(&line));
		line = NULL;
	//	ft_strdel(&line);
	}
	return (ret);
}
