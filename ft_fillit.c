/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:59 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/18 19:59:18 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_lr(int *map, int *tab, int i, int size)
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

int		is_fillit(int *map, int *tab, int size_map, int size)
{
	int	i;
	int	save_size;
	int	new_size;
	int	*map_tmp;
	int	*save_map;
	int	*save_tab;
	int	*tab_tmp;
	int	*sv_tab;

	i = -1;
	tab_tmp = tab;
	sv_tab = tab;
	save_size = 0;
	while (++i < size_map)
	{
		fill_lr(map, tab_tmp, i, size);
		map_tmp = map;
		if ((new_size = fill_map(map_tmp, tab_tmp, i, size)) > size_map)
		{
			if (!save_size)
				save_size = new_size;
			if (new_size < save_size)
			{
				save_tab = tab_tmp;
				save_size = new_size;
				save_map = map_tmp;
			}
			bit_down(sv_tab, ++size);
			printf("NON\n", size_map);
			print_bit(sv_tab, size);
			putchar('\n');
			tab_tmp = sv_tab;
		}
		else
		{
			map = map_tmp;
			return (size_map);
		}
	}
	tab = save_tab;
	return (save_size);
}

int		fillit(int *map, t_tetri *tetri, int length)
{
	int	i;
	int	j;
	int	size;
	int	size_map;

	j = -1;
	size_map = get_size(tetri[0].tab);
	while (++j < length)
	{
		size = get_size(tetri[j].tab);
		print_bit(tetri[j].tab, size);
		printf("Tetri\n");		
		size_map = is_fillit(map, tetri[j].tab, size_map, size);
		printf("%d\n", size_map);
		print_bit(map, size_map);
		putchar('\n');
		sleep(2);
	}
	return (size_map);
}
