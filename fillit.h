/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:56:28 by gubourge          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/20 13:47:44 by daugier          ###   ########.fr       */
=======
/*   Updated: 2016/03/21 12:05:00 by gubourge         ###   ########.fr       */
>>>>>>> 9c65b8f85713eb541644a65e4e2fac21ac021d0c
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define MAX(x, y) (x > y ? x : y)

typedef struct	s_tetris2
{
<<<<<<< HEAD
	int			tetris[4];
=======
	int			*tab;
>>>>>>> 9c65b8f85713eb541644a65e4e2fac21ac021d0c
	char		carac;
}				t_tetris2;

typedef struct	s_tetri
{
	int			map[16];
	int			nb_tetris;
	t_tetris2	*tetris;
}				t_tetri;

void	bit_convert(char *buf, t_tetri *tetris);
char	*ft_getmap(char *str, int fd);
void	print_bit(int *tab, int size);
int		ft_check_map(char *buf, t_tetri *tetris);
void	bit_reset(int *tab, int size);
int		fillit(t_tetri *tetris, int length);
void	print_square(t_tetri *tetris, int size, int length);
int		ft_power(int nb, int power);
int		get_size(int *tab);
void	bit_up(int *tab, int size);
void	bit_down(int *tab, int size);
void	bit_left(int *tab, int size);
void	bit_right(int *tab, int size);

#endif
