/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:07:14 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/09 12:11:01 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	copy = (char*)malloc(sizeof(char) * (i + 1));
	i = -1;
	if (copy)
	{
		while (s1[++i])
			copy[i] = s1[i];
		copy[i] = '\0';
		return (copy);
		free(copy);
	}
	return (NULL);
}
