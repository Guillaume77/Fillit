/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <jlange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 02:40:35 by jlange            #+#    #+#             */
/*   Updated: 2016/03/21 16:59:29 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_decale_bin(t_tetris *tetris)
{
	int		i;
	int		j;
	int		k;

	j = -1;
	while (++j < tetris->nb_tetris)
	{
		i = -1;
		while (++i < 4)
		{
			k = -1;
			if (!(tetris->tetris[j].tetris[0] & 1) && (tetris->tetris[j].tetris[1] &  1) &&
					(tetris->tetris[j].tetris[2]) & 1) && (tetris->tetris[j].tetris[3] & 1)
			{
				while (++k < 4)
					tetris->tetris[j].tetris[k]  >>= 1;
			}
			if (tetris->tetris[j].tetris[0] == 0)
			{
				tetris->tetris[j].tetris[0] = tetris->tetris[j].tetris[1];
				tetris->tetris[j].tetris[1] = tetris->tetris[j].tetris[2];
				tetris->tetris[j].tetris[2] = tetris->tetris[j].tetris[3];
				tetris->tetris[j].tetris[3] = 0;
			}
		}
	}
}
