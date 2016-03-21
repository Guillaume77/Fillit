/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:29:27 by daugier           #+#    #+#             */
/*   Updated: 2016/03/21 14:24:22 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_size(t_infos *s, int size)
{
	int		i;
	
	i = -1;
	while (++i < size)
	{
		MAP[i] = MAX;
		MAP[i] -= ft_power(2, size) - 1;
	}
	while (i < 16)
	{
		MAP[i] = MAX;
		i++;
	}
	MAP[i] = MAX;
}

int		square_min(t_infos *s)
{
	int	square;
	int	nb;

	square = 1;
	nb = s->nb_tetris * 4;
	while (nb > square * square)
		square++;
	return (square);
}
