/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:03:57 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/02 21:03:58 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_img
{
	void			*img;
	int				width;
	int				height;
}				t_img;

typedef struct s_mlx
{
	void	*mp;
	void	*mw;
}				t_mlx;

typedef struct s_assets
{
	t_img	coin;
	t_img	player;
	t_img	exit_open;
	t_img	exit_closed;
	t_img	wall;
	t_img	enemy;
	t_mlx	m;
	int		cc;
	int		mv;
	char	**level;
}				t_assets;
typedef struct s_vector2
{
	int	i;
	int	j;
}				t_vec2;

int			map_parser(char	**level, char *map, int	*coin_counter);
int			render_frames(t_assets *assets);
int			increment_position(t_assets *assets);
t_assets	render_level(t_assets assets);
void		move_up(char **level, int	*coin_counter);
void		move_right(char	**level, int	*coin_counter);
void		move_down(char	**level, int	*coin_counter);
void		move_left(char	**level, int	*coin_counter);
t_img		render_enemy2(t_mlx mlx, char **level);
t_img		render_exit(t_mlx mlx, char **level);
t_img		render_player(t_mlx mlx, char **level);
t_img		render_player2(t_mlx mlx, char **level);
t_img		render_collectible(t_mlx mlx, char **level);
t_img		render_walls(t_mlx mlx, char **level);
void		*window_creator(t_mlx mlx, char	**level);
t_img		image_creator(t_mlx mlx, char	*filename);
#endif