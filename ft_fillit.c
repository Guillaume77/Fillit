/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 15:03:52 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_lr(int *map, int *tab, int i, int size, int size_map)
{
	int	cpt;
	int	sv_i;

	cpt = 1;
	sv_i = i;
	while (cpt)
	{
		cpt = 0;
		while (i < size)
		{
			if (map[i] & tab[i])
				cpt = 1;
			if (check_length(map[i] & tab[i]) >= size_map)
				return (0);
			i++;
		}
		i = sv_i;
		if (cpt)
			bit_right(tab, size);
	}
	return (1);
}

int		fill_map(int *map, int *tab, int i, int size)
{
	while (i < size)
	{
		map[i] |= tab[i];
		i++;
	}
	return (get_size(map));
}

void	copy_tab(int *a, int *b)
{
	int	i;

	i = -1;
	while (++i < 26)
		a[i] = b[i];
}

int		is_fillit(int *map, int *tab, int size_map, int size)
{
	int	sv_tab[26];
	int	i;

	i = 0;
	copy_tab(sv_tab, tab);
	while (!(fill_lr(map, tab, i, size, size_map)))
	{
		if (!bit_down(sv_tab, ++size))
		{
/*		supprime le tetri (map + reinitialisation);
		tetri--;
		tetri[n]++;
		check(tetri);
		tetri++;
*/			
		copy_tab(tab, sv_tab);
		i++;
	}
	if ((new_size = fill_map(map_tmp, tab_tmp, i, size)) > size_map)
}

int		fillit(int *map, t_tetri *tetri, int length)
{
	int	i;
	int	j;
	int	size;
	int	size_map;

	j = -1;
	size_map = square_min(nb_tetris);
	while (++j < nb_tetris)
	{
		is_fillit(map, tetri[j].tab, size_map, size);
	}
	return (size_map);
}
