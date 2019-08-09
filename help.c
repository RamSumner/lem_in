/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:29:39 by rsumner           #+#    #+#             */
/*   Updated: 2019/07/11 13:26:35 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



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