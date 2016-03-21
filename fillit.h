/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:56:28 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/21 12:05:00 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX(x, y) (x > y ? x : y)

typedef struct	s_tetri
{
	int			*tab;
	char		carac;
}				t_tetri;

void	bit_reset(int *tab, int size);
int		fillit(int *map, t_tetri *tetri, int length);
void	print_square(int *map, t_tetri *tetri, int size, int length);
int		ft_power(int nb, int power);
int		get_size(int *tab);
void	bit_up(int *tab, int size);
void	bit_down(int *tab, int size);
void	bit_left(int *tab, int size);
void	bit_right(int *tab, int size);

#endif
