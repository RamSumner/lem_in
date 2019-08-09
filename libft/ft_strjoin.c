/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:52:18 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/10 17:50:19 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
	{
		if ((buff = ft_strnew(ft_strlen(s1))))
			buff = ft_strcpy(buff, s1);
	}
	else if (s2 && !s1)
	{
		if ((buff = ft_strnew(ft_strlen(s2))))
			buff = ft_strcpy(buff, s2);
	}
	else
	{
		if ((buff = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcpy(buff, s1);
			ft_strcat(buff, s2);
		}
	}
	return (buff);
}
