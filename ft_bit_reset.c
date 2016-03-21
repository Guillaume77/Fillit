/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:05:48 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 13:38:02 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		bit_convert(char *str)
{
	int	i;
	int	power;
	int	nb;

	nb = 0;
	i = 0;
	power = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nb += ft_power(2, power);
		++i;
		++power;
	}
	return (nb);
}

int		is_more_left(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] & 1)
			return (0);
	return (1);
}

void	bit_reset(int *tab, int size)
{
	while (tab[0] == 0)
		bit_up(tab, size);
	while (is_more_left(tab, size))
		bit_left(tab, size);
}
