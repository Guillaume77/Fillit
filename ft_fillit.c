/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/24 12:19:20 by gubourge         ###   ########.fr       */
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
	while (i < (tetris->y + tetris->i))
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
		get_size(&TET[j]);
		copy_tab(TET[j].sv_tetris, TET[j].tetris);
		while (!(fill_lr(tetris->map, &(TET[j]), size_map)))
		{
			if ((++(TET[j].i) + TET[j].y) <= size_map)
			{
				bit_down(TET[j].sv_tetris, ++(TET[j].size));
				copy_tab(TET[j].tetris, TET[j].sv_tetris);
				if (j == 3)
				{
					printf("Tetris\n");
					print_bit(TET[j].tetris, size_map);
					putchar('\n');
					printf("Tetris_sv\n");
					print_bit(TET[j].sv_tetris, size_map);
					putchar('\n');
					printf("i = %d\ny = %d\n", TET[j].i, TET[j].y);
					sleep(3);
				}
					
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
		if (j == 3)
		{
			printf("Map Before\n");
			print_bit(tetris->map, size_map);
			putchar('\n');
			printf("Tetris\n");
			print_bit(TET[j].tetris, size_map);
			putchar('\n');
		}
		fill_map(tetris->map, &(TET[j]));
		if (j == 3)
		{
			printf("Map After\n");
			print_bit(tetris->map, size_map);
			putchar('\n');
			sleep(3);
		}
	}
	return (0);
}

int		fillit(t_tetri *tetris)
{
	int	size_map;
	int	i;

	i = -1;
	while (++i < tetris->nb_tetris)
	{
	}
	size_map = square_min(tetris);
	printf("sizemap = %d\n", size_map);
	while (is_fillit(tetris, size_map))
		++size_map;
	return (size_map);
}
