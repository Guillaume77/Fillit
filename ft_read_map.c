/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:09:56 by gubourge          #+#    #+#             */
/*   Updated: 2016/03/19 14:27:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcharjoin(char *s1, char s2)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	i = 0;
	if (ptr == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	if (s1[i] == '\0')
	{
		ptr[i] = s2;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_getmap(char *str, int fd)
{
	int		i;
	char	c;

	i = 0;
	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (read(fd, &c, 1))
	{
		str = ft_strcharjoin(str, c);
		if (c != '\n' && c != '.' && c != '#')
			return (NULL);
	}
	if (str[0] == '\n')
		return (NULL);
	return (str);
}
