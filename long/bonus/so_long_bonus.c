/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:05:38 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/02 21:02:22 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	check_double_newline(char	*tmp)
{
	static int	status;

	if (tmp[0] == '\n')
		status++;
	else
		status = 0;
	if (status > 1)
		return (ft_printf("Error: Extra newline"), exit(-1), 0);
	return (0);
}

int	prep_map(int ac, char **av, char ***level, int	*coin_counter)
{
	int		fd;
	char	*tmp;
	char	*map;
	int		s;

	map = NULL;
	if (ac == 2)
	{
		s = ft_strlen(av[1]);
		if (!ft_strncmp(&av[1][s - 5], ".ber", 4))
			return (-2);
		tmp = malloc(2);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (perror("Error"), -1);
		while (read (fd, tmp, 1))
		{
			tmp[1] = 0;
			check_double_newline(tmp);
			map = ft_strjoin(map, tmp);
		}
		*level = ft_split(map, '\n');
		return (free(tmp), map_parser(*level, map, coin_counter));
	}
	return (-2);
}

int	key_handler(int keycode, t_assets *assets)
{
	if (keycode == 53)
		exit(-1);
	if (keycode == 0)
		return (move_left(assets->level, &assets->cc),
			render_level(*assets), 0);
	if (keycode == 1)
		return (move_down(assets->level, &assets->cc),
			render_level(*assets), 0);
	if (keycode == 13)
		return (move_up(assets->level, &assets->cc),
			render_level(*assets), 0);
	if (keycode == 2)
		return (move_right(assets->level, &assets->cc),
			render_level(*assets), 0);
	return (-1);
}

int	close_window(t_assets *assets)
{
	mlx_destroy_window(assets->m.mp, assets->m.mw);
	exit(-1);
}

int	main(int ac, char **av)
{
	int			status;
	t_assets	assets;

	assets.cc = 0;
	assets.mv = 1;
	status = prep_map(ac, av, &assets.level, &assets.cc);
	if (status != 0)
	{
		if (status == -1)
			return (-1);
		else
			return (ft_printf("error: Provide a map!\n"), -1);
	}
	assets.m.mp = mlx_init();
	assets.m.mw = window_creator(assets.m, assets.level);
	increment_position(&assets);
	assets = render_level(assets);
	mlx_hook(assets.m.mw, 2, 0, key_handler, &assets);
	mlx_hook(assets.m.mw, 17, 0, close_window, &assets);
	mlx_loop_hook(assets.m.mp, render_frames, &assets);
	mlx_loop(assets.m.mp);
	return (0);
}
