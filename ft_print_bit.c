/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:05:58 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/18 18:35:16 by gubourge         ###   ########.fr       */
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
}

void	print_square(int *map, t_tetri *tetri, int size, int length)
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
				if ((tetri[j].tab[i] >> dec_bit) & 1)
				{
					count = 0;
					write(1, &(tetri[j].carac), 1);
				}
			if (count)
				write(1, ".", 1);
		}
		write(1, "\n", 1);
	}
}
