/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:05:58 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/20 13:48:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	print_bit(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			putchar('0' + ((tab[i] >> j) & 1));
			++j;
		}
		putchar('\n');
	}
	putchar('\n');
}

void	print_square(t_tetri *tetris, int size, int length)
{
	int		i;
	int		j;
	int		dec_bit;
	char	count;

	i = -1;
	while (++i < size)
	{
		dec_bit = -1;
		while (++dec_bit < size)
		{
			count = 1;
			j = -1;
			while (++j < length)
				if ((tetris->tetris[i].tetris[j] >> dec_bit) & 1)
				{
					count = 0;
					write(1, &tetris->tetris[i].carac, 1);
				}
			if (count)
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}
