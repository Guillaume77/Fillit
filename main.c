/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:38:15 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 13:12:00 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ft_check_map(av[1], &tetris))
		{
			while (++i < tetris.nb_tetris)
				print_bit(tetris.tetris[i].tetris, 4);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}
