/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:14 by orubin            #+#    #+#             */
/*   Updated: 2019/12/11 18:10:21 by orubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_tetro
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
}					t_tetro;
int					ft_valid_char(char *tetro, int j);
char				*ft_tetro_str(int fd);
int					ft_valid_str(char *tetro);
int					ft_valid_tetro(char *tetro, int j);
int					ft_count_tetro(char *str);
void				ft_inc_tetro(t_tetro **tmp, char *str);
t_tetro				*ft_set_tetro(char *str);
char				**ft_new_map(char **map, int size);
int					ft_check_tetris(char **map, t_tetro *tetris, int size);
char				**ft_clean_map(char **map, t_tetro *tetris, int size);
char				**ft_set_map(char **map, t_tetro *tetris, int size);
void				ft_view_map(char **map);
void				ft_pos_xy(t_tetro **tetris, int x, int y);
char				**ft_align(char **tetro_map, t_tetro *tetris, int size);
void				ft_decision(t_tetro *tetris, char *str);
void				ft_free_tetris(t_tetro *list);
int					ft_sqrt(int nb);
void				ft_free_map(char **map);

#endif
