/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:29:27 by daugier           #+#    #+#             */
/*   Updated: 2016/03/24 13:40:30 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		square_min(t_tetri *s)
{
	int	square;
	int	nb;

	square = 1;
	nb = s->nb_tetris * 4;
	while (nb > square * square)
		square++;
	return (square);
}

void	ft_init_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		tab[i++] = 0;
}

int		check_length(int length)
{
	int	nb;

	nb = 0;
	while (length > 0)
	{
		length /= 2;
		nb++;
	}
	return (nb);
}

void	copy_tab(int *a, int *b)
{
	int	i;

	i = -1;
	while (++i < 16)
		a[i] = b[i];
}
