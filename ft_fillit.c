/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/25 14:30:06 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_lr(int *map, t_tetris2 *tetris, int size_map)
{
	int	cpt;
	int	i;

	cpt = 1;
	i = tetris->i;
	while (cpt)
	{
		cpt = 0;
		while (i < (tetris->y + tetris->i))
		{
			if ((map[i] & TET[i]) > 0)
				cpt = 1;
			if ((check_length(map[i] | TET[i]) > size_map)
				|| ((i + 1) > size_map))
				return (0);
			i++;
		}
		i = tetris->i;
		if (cpt)
			bit_right(TET, tetris->size);
	}
	return (1);
}

int		fill_map(int *map, t_tetris2 *tetris)
{
	int	i;

	i = tetris->i;
	while (i < (tetris->y + tetris->i))
	{
		map[i] |= TET[i];
		i++;
	}
	return (0);
}

void	delete_tetris_map(t_tetris2 *tetris, int *map)
{
	int	i;

	i = tetris->i;
	while (i < (tetris->y + tetris->i))
	{
		map[i] ^= TET[i];
		i++;
	}
}

int		is_fillit(t_tetri *tetris, int size_map, int j)
{
	while (++j < tetris->nb_tetris)
	{
		get_size(&TET[j]);
		copy_tab(TET[j].sv_tetris, TET[j].tetris);
		while (!(fill_lr(tetris->map, &(TET[j]), size_map)))
		{
			if ((++(TET[j].i) + TET[j].y) <= size_map)
			{
				bit_down(TET[j].sv_tetris, ++(TET[j].size));
				copy_tab(TET[j].tetris, TET[j].sv_tetris);
			}
			else
			{
				bit_reset(TET[j].tetris, TET[j].size);
				if (--j == -1)
					return (1);
				delete_tetris_map(&(TET[j]), tetris->map);
				bit_right(TET[j].tetris, TET[j].size);
			}
		}
		fill_map(tetris->map, &(TET[j]));
	}
	return (0);
}

int		fillit(t_tetri *tetris)
{
	int	size_map;

	size_map = square_min(tetris);
	while (is_fillit(tetris, size_map, -1))
		++size_map;
	return (size_map);
}
