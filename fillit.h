/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:33:34 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/25 14:34:07 by daugier          ###   ########.fr       */
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

# define MAX(x, y) (x > y ? x : y)
# define TET tetris->tetris
# define I tab[0]
# define J tab[1]
# define K tab[2]

typedef struct	s_tetris2
{
	int			tetris[16];
	int			sv_tetris[16];
	int			i;
	int			y;
	int			size;
	char		carac;
}				t_tetris2;

typedef struct	s_tetri
{
	int			map[16];
	int			nb_tetris;
	t_tetris2	*tetris;
}				t_tetri;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			bit_convert(char *buf, t_tetri *tetris);
void			print_square(t_tetri *tetris, int size);
void			ft_init_tab(int *tab, int size);
char			*ft_getmap(char *str, int fd);
void			print_bit(int *tab, int size);
int				ft_check_map(char *buf, t_tetri *tetris);
void			bit_reset(int *tab, int size);
int				fillit(t_tetri *tetris);
int				ft_power(int nb, int power);
void			get_size(t_tetris2 *tetris);
void			bit_up(int *tab, int size);
void			bit_down(int *tab, int size);
void			bit_left(int *tab, int size);
void			bit_right(int *tab, int size);
int				square_min(t_tetri *s);
int				check_length(int length);
void			copy_tab(int *a, int *b);

#endif
