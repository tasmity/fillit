/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:25:59 by orubin            #+#    #+#             */
/*   Updated: 2019/12/11 16:26:52 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_new_map(char **map, int size)
{
	int		x;
	int		y;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		if (!(map[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			++x;
		}
		map[y][x] = '\0';
		++y;
	}
	map[y] = 0;
	return (map);
}

char		**ft_clean_map(char **map, t_tetro *tetris, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetris->c)
				map[y][x] = '.';
			++x;
		}
		++y;
	}
	return (map);
}

char		**ft_set_map(char **map, t_tetro *tetris, int size)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetris->y[i] == y && tetris->x[i] == x)
			{
				map[y][x] = tetris->c;
				++i;
			}
			++x;
		}
		++y;
	}
	return (map);
}

void		ft_view_map(char **map)
{
	int		i;

	if (map == NULL)
	{
		ft_putendl("error");
		return ;
	}
	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		++i;
	}
}

void		ft_free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
