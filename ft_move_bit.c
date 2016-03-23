/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:45:06 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/23 16:09:18 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_length(int length, int size_map, int size)
{
	int	nb;

	nb = 0;
	while (length > 0)
	{
		length /= 2;
		nb++;
	}
	if (size_map >= size)
		return (nb);
	return (size_map + 1);
}

int		get_size(int *tab)
{
	int	i;
	int	size;
	int	max_size;
	int	tmp;

	i = -1;
	max_size = 0;
	while (tab[++i])
	{
		size = 0;
		tmp = tab[i];
		while (tmp > 0)
		{
			tmp /= 2;
			size++;
		}
		if (size > max_size)
			max_size = size;
	}
	return (MAX(i, size));
}

void	bit_up(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == size - 1)
			tab[i] = 0;
		else
			tab[i] = tab[i + 1];
		++i;
	}
}

void	bit_down(int *tab, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (i == 0)
			tab[i] = 0;
		else
			tab[i] = tab[i - 1];
		--i;
	}
}

void	bit_left(int *tab, int size)
{
	while (--size >= 0)
		tab[size] >>= 1;
}

void	bit_right(int *tab, int size)
{
	while (--size >= 0)
		tab[size] <<= 1;
}
