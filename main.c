/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:33:42 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 16:50:01 by gubourge         ###   ########.fr       */
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
		tetris.map[0] = 0;
		tetris.map[1] = 0;
		tetris.map[2] = 0;
		tetris.map[3] = 0;
		tetris.map[4] = 0;
		tetris.map[5] = 0;
		tetris.map[6] = 0;
		tetris.map[7] = 0;
		tetris.map[8] = 0;
		tetris.map[9] = 0;
		tetris.map[10] = 0;
		tetris.map[11] = 0;
		tetris.map[12] = 0;
		tetris.map[13] = 0;
		tetris.map[14] = 0;
		tetris.map[15] = 0;
		print_bit(tetris.map, 16);
		sleep(2);
		if (ft_check_map(av[1], &tetris))
		{
			printf("JE PUE\n");
			fillit(&tetris);
//			print_square()
		}
		else
			ft_putstr("error\n");
	}
}
