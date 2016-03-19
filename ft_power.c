/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:29:25 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/18 18:33:28 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int	value;

	value = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (--power > 0)
		value *= nb;
	return (value);
}
