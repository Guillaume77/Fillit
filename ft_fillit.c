/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/23 16:21:38 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_lr(int *map, t_tetris2 *tetris, int size_map)
{
	int	cpt;
	int	sv_i;

	cpt = 1;
	sv_i = tetris->i;
	while (cpt)
	{
		cpt = 0;
		while (tetris->i < tetris->size)
		{
			if (map[tetris->i] & TET[tetris->i])
				cpt = 1;
			if (check_length(map[tetris->i] | TET[tetris->i], size_map, tetris->size) > size_map)
				return (0);
			tetris->i++;
		}
		tetris->i = sv_i;
		if (cpt)
			bit_right(TET, tetris->size);
	}
	return (1);
}

int		fill_map(int *map, t_tetris2 *tetris)
{
	int	i;

	i = tetris->i;
	while (i < tetris->size)
	{
		map[i] |= TET[i];
		i++;
	}
	return (get_size(map));
}

void	copy_tab(int *a, int *b)
{
	int	i;

	i = -1;
	while (++i < 16)
		a[i] = b[i];
}

void	delete_tetris_map(t_tetris2 *tetris, int *map)
{
	int	i;

	i = tetris->i;
	while (i < tetris->size)
	{
		map[i] ^= TET[i];
		i++;
	}
//	tetris->i = 0;
//	bit_reset(TET, tetris->size);
//	bit_reset(tetris->sv_tetris, tetris->size);
//	tetris->size = get_size(TET);
}

int		is_fillit(t_tetri *tetris, int size_map)
{
	int	j;

	j = -1;
	while (++j < tetris->nb_tetris)
	{
		TET[j].size = get_size(TET[j].tetris);
		copy_tab(TET[j].sv_tetris, TET[j].tetris);
		while (!(fill_lr(tetris->map, &(TET[j]), size_map)))
		{
			if (++(TET[j].size) <= size_map)		
			{
				bit_down(TET[j].sv_tetris, TET[j].size);
				copy_tab(TET[j].tetris, TET[j].sv_tetris);
				(TET[j].i)++;
			}
			else
			{
				bit_reset(TET[j].tetris, TET[j].size);
				bit_reset(TET[j].sv_tetris, TET[j].size);
				TET[j].size = get_size(TET[j].tetris);
				TET[j].i = 0;
				if (--j == -1)
					return (1);
//				if (j == 3)
//				{
//					print_bit(tetris->map, 10);
//					putchar('\n');
//					print_bit(TET[j].tetris, 10);
//					putchar('\n');
//				}
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
	while (is_fillit(tetris, size_map))
	{
		++size_map;
	}
	return (size_map);
}
