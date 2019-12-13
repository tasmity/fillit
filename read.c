/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:04 by orubin            #+#    #+#             */
/*   Updated: 2019/12/13 16:09:29 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_tetro_str(int fd)
{
	char	*str;
	char	c;
	int		i;
	int		rev;

	i = 0;
	str = NULL;
	rev = read(fd, &c, 1);
	if (rev < 0)
		return (NULL);
	if (rev == 1)
	{
		str = (char *)malloc(sizeof(char) * 546);
		while (rev != '\0')
		{
			str[i] = c;
			++i;
			if (i > 545)
				return (0);
			rev = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}

int			ft_count_tetro(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			++count;
		++i;
	}
	return (count / 4);
}

void		ft_inc_tetro(t_tetro **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			++j;
		}
		++i;
	}
	free(str);
}

t_tetro		*ft_set_tetro(char *str)
{
	int		c_tetro;
	int		j;
	char	c;
	t_tetro	*set;
	t_tetro	*tmp;

	j = 0;
	c = 'A';
	c_tetro = ft_count_tetro(str);
	if (!(set = (t_tetro *)malloc(sizeof(t_tetro))))
		return (NULL);
	tmp = set;
	while (c_tetro > 0)
	{
		tmp->c = c;
		ft_inc_tetro(&tmp, ft_strsub(str, j, 20));
		if (!(tmp->next = (t_tetro *)malloc(sizeof(t_tetro))))
			return (NULL);
		tmp = tmp->next;
		--c_tetro;
		++c;
		j += 21;
	}
	tmp->next = NULL;
	return (set);
}

void		ft_free_tetris(t_tetro *list)
{
	t_tetro *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
