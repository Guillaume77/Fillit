/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:29:27 by daugier           #+#    #+#             */
/*   Updated: 2016/03/21 16:23:19 by gubourge         ###   ########.fr       */
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
