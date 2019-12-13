/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:25:56 by orubin            #+#    #+#             */
/*   Updated: 2019/12/11 16:56:11 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*tetro;
	t_tetro	*tetris;

	if (argc != 2)
	{
		ft_putendl("usage: source_file");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	tetro = ft_tetro_str(fd);
	if (!ft_valid_str(tetro))
	{
		free(tetro);
		ft_putendl("error");
		return (1);
	}
	close(fd);
	tetris = ft_set_tetro(tetro);
	ft_decision(tetris, tetro);
	return (0);
}
