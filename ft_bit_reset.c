/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:12:53 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/25 14:33:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bit_convert(char *buf, t_tetri *tetris)
{
	int tab[3];
	int	power;

	I = -1;
	J = -1;
	tetris->tetris = (t_tetris2*)malloc(sizeof(t_tetris2) * tetris->nb_tetris);
	while (buf[++I])
	{
		K = 0;
		ft_init_tab(TET[++J].tetris, 16);
		TET[J].carac = 'A' + J;
		while ((buf[I] != '\n' && buf[I + 1] != '\n') && buf[I--])
		{
			power = 0;
			while (buf[++I] != '\n')
			{
				if (buf[I] == '#')
					TET[J].tetris[K] += ft_power(2, power);
				power++;
			}
			K++;
			I++;
		}
		bit_reset(TET[J].tetris, 4);
	}
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
