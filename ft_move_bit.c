/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:45:06 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/24 13:39:02 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_size(t_tetris2 *tetris)
{
	int	i;
	int	size;
	int	max_size;
	int	tmp;

	i = -1;
	max_size = 0;
	while (TET[++i] > 0)
	{
		size = 0;
		tmp = TET[i];
		while (tmp > 0)
		{
			tmp /= 2;
			size++;
		}
		if (size > max_size)
			max_size = size;
	}
	tetris->y = i;
	tetris->i = 0;
	tetris->size = (MAX(i, size));
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
