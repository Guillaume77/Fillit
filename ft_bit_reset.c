/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:12:53 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/25 14:23:14 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	bit_convert(char *buf, t_tetri *tetris)
{
	int	i;
	int	j;
	int	k;
	int	power;

	i = -1;
	j = -1;
	tetris->tetris = (t_tetris2*)malloc(sizeof(t_tetris2) * tetris->nb_tetris);
	while (buf[++i])
	{
		k = 0;
		ft_init_tab(TET[++j].tetris, 16);
		TET[j].carac = 'A' + j;
		while ((buf[i] != '\n' && buf[i + 1] != '\n') && buf[i--])
		{
			power = 0;
			while (buf[++i] != '\n')
			{
				if (buf[i] == '#')
					TET[j].tetris[k] += ft_power(2, power);
				power++;
			}
			k++;
			i++;
		}
		bit_reset(TET[j].tetris, 4);
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
