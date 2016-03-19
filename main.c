/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:15 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/18 19:30:20 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{	
	t_tetri tetri[4];
	int	map[26];
	int	i;

	i = 0;
	while (i < 4)
	{
		bzero(tetri[i].tab, 26);
		tetri[i].tab[0] = 3;
		tetri[i].tab[1] = 3;
		tetri[i].tab[2] = 0;
		tetri[i].tab[3] = 0;
		bit_reset(tetri[i].tab, 4);
		++i;
	}	
	bzero(map, 26);
	print_bit(tetri[0].tab, 26);
	putchar('\n');
	print_square(map, tetri, fillit(map, tetri, 4), 4);
	return (0);
}
