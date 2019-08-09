/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:53:49 by rsumner           #+#    #+#             */
/*   Updated: 2019/07/08 11:17:22 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*buff;

	buff = NULL;
	if (!s1 && s2)
	{
		if ((buff = ft_strnew(n)))
			buff = ft_strncpy(buff, s2, n);
	}
	else
	{
		if ((buff = ft_strnew(ft_strlen(s1) + n)))
		{
			ft_strcpy(buff, s1);
			ft_strncat(buff, s2, n);
		}
	}
	free((char *)s1);
	return (buff);
}

char	*ft_move(char *str, int i)
{
	str = ft_strcpy(&str[0], &str[i + 1]);
	ft_bzero(&str[BUFF_SIZE - i + 1], i);
	return (str);
}

int		ft_read(const int fd, char **tab, char **line)
{
	int		r;
	int		i;
	char	*s;

	r = 0;
	i = -1;
	s = *tab;
	while (i == -1)
	{
		if (r == -1 || (s[0] == '\0' && (r = read(fd, s, BUFF_SIZE)) <= 0))
			return (r);
		while (s[++i] != '\n' && s[i] != '\0')
			;
		if (!(*line = ft_strnjoin(*line, s, i)))
			return (-1);
		if (s[i] != '\n')
		{
			ft_bzero(s, BUFF_SIZE);
			if ((r = read(fd, s, BUFF_SIZE)))
				i = -1;
		}
		else
			s = ft_move(s, i);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab[10240];
	int			result;

	if (fd == -2)
	{
		result = -1;
		while (tab[++result])
			ft_strdel(&tab[result]);
	}
	result = -2;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || BUFF_SIZE > 2147483647\
			|| fd > 10240 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(tab[fd]) && !(tab[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;
	result = ft_read(fd, &tab[fd], line);
	if (result == 0)
		ft_strdel(&tab[fd]);
	return (result);
}
