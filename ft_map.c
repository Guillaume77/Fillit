/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:29:27 by daugier           #+#    #+#             */
/*   Updated: 2016/03/22 14:02:44 by daugier          ###   ########.fr       */
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
