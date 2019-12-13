/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:01 by orubin            #+#    #+#             */
/*   Updated: 2019/12/11 18:51:43 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int		i;

	i = 1;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			else if (i >= 46341)
				return (0);
			++i;
		}
	}
	return (i - 1);
}

void		ft_pos_xy(t_tetro **tetris, int x, int y)
{
	int		i;
	int		pos_x;
	int		pos_y;

	i = 0;
	pos_x = 27;
	pos_y = 27;
	while (i < 4)
	{
		if ((*tetris)->x[i] < pos_x)
			pos_x = (*tetris)->x[i];
		if ((*tetris)->y[i] < pos_y)
			pos_y = (*tetris)->y[i];
		++i;
	}
	--i;
	while (i >= 0)
	{
		(*tetris)->x[i] = (*tetris)->x[i] - pos_x + x;
		(*tetris)->y[i] = (*tetris)->y[i] - pos_y + y;
		--i;
	}
}

char		**ft_align(char **tetro_map, t_tetro *tetris, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetris->next == NULL)
		return (tetro_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_pos_xy(&tetris, x, y);
			if (ft_check_tetris(tetro_map, tetris, size))
				map = ft_align(ft_set_map(tetro_map, tetris, size),
						tetris->next, size);
			if (map)
				return (map);
			tetro_map = ft_clean_map(tetro_map, tetris, size);
			++x;
		}
		++y;
	}
	return (NULL);
}

void		ft_decision(t_tetro *tetris, char *str)
{
	char	**full_map;
	char	**tetro_map;
	int		size;

	size = ft_sqrt(ft_count_tetro(str) * 4);
	tetro_map = NULL;
	tetro_map = ft_new_map(tetro_map, size);
	while (!(full_map = ft_align(tetro_map, tetris, size)))
	{
		++size;
		ft_free_map(tetro_map);
		tetro_map = ft_new_map(tetro_map, size);
	}
	ft_view_map(full_map);
	ft_free_map(tetro_map);
	free(str);
	ft_free_tetris(tetris);
}
