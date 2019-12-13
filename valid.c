/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:11 by orubin            #+#    #+#             */
/*   Updated: 2019/12/03 22:32:55 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_valid_char(char *tetro, int j)
{
	int		dot;
	int		grid;
	int		line;
	int		i;

	dot = 0;
	grid = 0;
	line = 0;
	i = 0;
	while (i + j < 20 + j && tetro[i + j] != '\0')
	{
		if (tetro[i + j] == '#')
			++grid;
		if (tetro[i + j] == '.')
			++dot;
		if (tetro[i + j] == '\n')
			++line;
		++i;
	}
	if (grid == 4 && dot == 12 && line == 4)
		return (1);
	return (0);
}

int			ft_valid_tetro(char *tetro, int j)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (tetro[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && tetro[i + j + 1] == '#')
				++count;
			if ((i + j - 1) >= (0 + j) && tetro[i + j - 1] == '#')
				++count;
			if ((i + j + 5) < (20 + j) && tetro[i + j + 5] == '#')
				++count;
			if ((i + j - 5) >= (0 + j) && tetro[i + j - 5] == '#')
				++count;
		}
		++i;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int			ft_valid_str(char *tetro)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tetro)
		return (0);
	while (tetro[i + j] != '\0')
	{
		if (!(ft_valid_tetro(tetro, j) && ft_valid_char(tetro, j)))
			return (0);
		i = 19;
		if (tetro[i + j] == '\n' && tetro[i + j + 1] == '\0')
			return (1);
		if (tetro[i + j] == '\n' && tetro[i + j + 1] == '\n' &&
					(tetro[i + j + 2] == '.' || tetro[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int			ft_check_tetris(char **map, t_tetro *tetris, int size)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetris->y[i] < size && tetris->x[i] < size &&
				map[tetris->y[i]][tetris->x[i]] == '.')
			{
				++i;
				if (i == 4)
					return (1);
			}
			++x;
		}
		++y;
	}
	return (0);
}
