/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:33:42 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/24 13:16:28 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri tetris;
	int		i;

	i = -1;
	if (ac < 2)
		ft_putstr("usage : enter one parameter\n");
	else if (ac > 2)
		ft_putstr("usage : enter one parameter only\n");
	else
	{
		ft_init_tab(tetris.map, 16);
		if (ft_check_map(av[1], &tetris))
		{
			print_square(&tetris, fillit(&tetris));
		}
		else
			ft_putstr("error\n");
	}
}
