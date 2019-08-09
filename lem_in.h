/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:01:24 by rsumner           #+#    #+#             */
/*   Updated: 2019/08/09 18:03:25 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H


# include <unistd.h>
# include <stdio.h> /* tmp!!! */
# define OK 0
# define ERR -1

/*------GETTING DATA-------*/
typedef struct			s_room
{
	char				*name;
	int					n; /* number in the raw for t_link */
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	int                 nb;
	struct s_link		*next;
}						t_link;

typedef struct			s_sum
{
	int                 n_ants;
    int                 n_rooms;
	int					n_links;
	int					start;
	int					end;
	t_room				*room;
	t_link				**links;
}						t_sum;

/*------FOR SOLUTION-------*/
typedef struct			s_step
{
	int					ant_num;
	int					from;
	int					dest;
	struct s_steps		*next;
}						t_step;		

typedef struct			s_moove
{
	int					step_n;
	t_step				*step;
	struct s_moove		*next;
}						t_moove;


int get_data(t_sum *s);
int add_room_list(t_room **room);
int add_link_list(t_link **link);
char **ft_clean_tab(char **tab);
int	get_nb(char *str, int *nb, int type);
int find_name_num(char *str, t_room *r);
char **ft_split(char *s, char c);
int find_solution(t_sum s);

#endif