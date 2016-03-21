/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_testmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:36:39 by daugier           #+#    #+#             */
/*   Updated: 2016/03/21 14:22:53 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tail(t_tetri *tetris, char *buf)
{
	int			i;
	int			diez;
	int			bsn;
	int			point;

	i = -1;
	tetris->nb_tetris = 0;
	while (buf[++i])
	{
		diez = 0;
		bsn = 0;
		point = 0;
		while ((buf[i] != '\n' || buf[i + 1] != '\n') && buf[i])
		{
			if (buf[i] == '#')
				diez++;
			if (buf[i] == '.')
				point++;
			if (buf[i] == '\n' && buf[i - 1] != '\n' && buf[i + 1])
				bsn++;
			if (buf[i] == '\n' && (point + diez) % 4 != 0)
				return (0);
			i++;
		}
		tetris->nb_tetris++;
		if (diez != 4 || point != 12 || bsn != 3)
			return (0);
	}
	return (1);
}

int		ft_check_piece(char *buf)
{
	int	i;
	int touch;

	i = -1;
	while (buf[++i])
	{
		touch = 0;
		while ((buf[i] != '\n' || buf[i + 1] != '\n') && buf[i])
		{
			if (buf[i] == '#' && buf[i - 1] == '#')
				touch++;
			if (buf[i] == '#' && buf[i + 1] == '#')
				touch++;
			if (buf[i] == '#' && buf[i - 5] == '#')
				touch++;
			if (buf[i] == '#' && buf[i + 5] == '#')
				touch++;
			i++;
		}
		if (touch < 6)
			return (0);
	}
	return (1);
}

int		ft_check_map(char *av, t_tetri *tetris)
{
	int		fd;
	char	*buf;

	buf = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	if (!(buf = ft_getmap(buf, fd)) || !(ft_check_tail(tetris, buf)) ||
			!(ft_check_piece(buf)))
		return (0);
	bit_convert(buf, tetris);
	close(fd);
	return (1);
}
