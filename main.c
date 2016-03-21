/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:15 by gubourge          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/21 13:12:00 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

=======
/*   Updated: 2016/03/21 12:19:06 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
>>>>>>> 9c65b8f85713eb541644a65e4e2fac21ac021d0c
#include "fillit.h"

int		main(int ac, char **av)
{	
<<<<<<< HEAD
	t_tetri tetris;
	int		i;

	i = -1;
	if (ac < 2)
		ft_putstr("usage : enter one parameter\n");
	else if (ac > 2)
		ft_putstr("usage : enter one parameter only\n");
	else
	{
		if (ft_check_map(av[1], &tetris))
		{
			while (++i < tetris.nb_tetris)
				print_bit(tetris.tetris[i].tetris, 4);
		}
		else
			ft_putstr("error\n");
	}
=======
	t_tetri tetri[4];
	int	*map;
	int	i;

	i = 0;
	map = (int *)malloc(sizeof(int) * 26);
	while (i < 4)
	{
		tetri[i].tab = (int *)malloc(sizeof(int) * 26);
		bzero(tetri[i].tab, 26);
		tetri[i].tab[0] = 3;
		tetri[i].tab[1] = 3;
		tetri[i].tab[2] = 0;
		tetri[i].tab[3] = 0;
		bit_reset(tetri[i].tab, 4);
		++i;
	}	
	bzero(map, 26);
	print_square(map, tetri, fillit(map, tetri, 4), 4);
>>>>>>> 9c65b8f85713eb541644a65e4e2fac21ac021d0c
	return (0);
}
