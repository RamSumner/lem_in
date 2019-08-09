/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:43:52 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/09 15:26:04 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_room_list(t_room **room)
{
	t_room	*tmp;
	t_room	*list;

	tmp = NULL;
	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		return (ERR);
	tmp->next = NULL;
	list = *room;
	tmp->next = list;
	*room= tmp;
	return (OK);
}

int		add_link_list(t_link **link)
{
	t_link	*tmp;
	t_link	*list;

	tmp = NULL;
	if (!(tmp = (t_link*)malloc(sizeof(t_link))))
		return (ERR);
	tmp->next = NULL;
	list = *link;
	tmp->next = list;
	*link= tmp;
	return (OK);
}