/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:35:12 by rsumner           #+#    #+#             */
/*   Updated: 2019/04/12 17:42:11 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int nb)
{
	int size;

	size = 0;
	if (nb < 0)
		size++;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		min;

	size = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (n == -2147483648)
	{
		str[size - 1] = '8';
		n = -214748364;
		size = size - 1;
	}
	min = 0;
	min = (n >= 0 ? 1 : -1);
	while (size > 0)
	{
		str[size - 1] = (n * min) % 10 + '0';
		n = n / 10;
		size--;
	}
	if (min == -1)
		str[0] = '-';
	return (str);
}
