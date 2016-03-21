/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 17:11:18 by gubourge         ###   ########.fr       */
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
			if (check_length(map[tetris->i] | TET[tetris->i]) >= size_map)
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
	printf("%d - size\n", tetris->size);
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

int		is_fillit(t_tetri *tetris, int size_map)
{
	int	sv_tab[16];
	int	size;
	int	i;
	int	j;

	j = -1;
	while (++j < tetris->nb_tetris)
	{
		TET[j].size = get_size(TET[j].tetris);
		copy_tab(sv_tab, TET[j].tetris);
//		print_bit(TET[j].tetris, 16);
//		putchar('\n');
		while (!(fill_lr(tetris->map, &(TET[j]), size_map)))
		{
			bit_down(sv_tab, ++(TET[j].size));				
/*		supprime le tetri (map + reinitialisation);
		tetri--;
		tetri[n]++;
		check(tetri);
		tetri++;
*/			copy_tab(TET[j].tetris, sv_tab);
			(TET[j].i)++;
		}
		fill_map(tetris->map, &(TET[j]));
		print_bit(tetris->map, 16);
		putchar('\n');
	}
	return (0);
}

int		fillit(t_tetri *tetris)
{
	int	size_map;

	size_map = square_min(tetris);
	while (is_fillit(tetris, size_map))
	{
		printf("NON\n");
		++size_map;
	}
	return (size_map);
}
