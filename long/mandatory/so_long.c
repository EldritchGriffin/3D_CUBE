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
#include "so_long.h"

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

int	prep_map(int ac, char **av, char ***lv, int	*c)
{
	int		fd;
	char	*tmp;
	char	*map;
	int		s;

	map = NULL;
	if (ac == 2)
	{
		s = ft_strlen(av[1]);
		if (av[1][s - 1] != 'r' || av[1][s - 2] != 'e'
			|| av[1][s - 3] != 'b' || av[1][s - 4] != '.')
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
		return (*lv = ft_split(map, '\n'), free(tmp), map_parser(*lv, map, c));
	}
	return (-2);
}

int	key_handler(int keycode, t_assets *assets)
{
	if (keycode == 53)
		exit(-1);
	if (keycode == 0)
		return (move_left(assets->level, &assets->coin_counter),
			render_level(*assets), increment_position(assets), 0);
	if (keycode == 1)
		return (move_down(assets->level, &assets->coin_counter),
			render_level(*assets), increment_position(assets), 0);
	if (keycode == 13)
		return (move_up(assets->level, &assets->coin_counter),
			render_level(*assets), increment_position(assets), 0);
	if (keycode == 2)
		return (move_right(assets->level, &assets->coin_counter),
			render_level(*assets), increment_position(assets), 0);
	return (-1);
}

int	close_window(t_assets *assets)
{
	mlx_destroy_window(assets->mlx.mlx_ptr, assets->mlx.mlx_window);
	exit(-1);
}

int	main(int ac, char **av)
{
	int			status;
	t_assets	assets;

	assets.coin_counter = 0;
	assets.movement_counter = 1;
	status = prep_map(ac, av, &assets.level, &assets.coin_counter);
	if (status != 0)
	{
		if (status == -1)
			return (-1);
		else
			return (ft_printf("error: Provide a map!\n"), -1);
	}
	assets.mlx.mlx_ptr = mlx_init();
	assets.mlx.mlx_window = window_creator(assets.mlx, assets.level);
	increment_position(&assets);
	assets = render_level(assets);
	mlx_hook(assets.mlx.mlx_window, 2, 0, key_handler, &assets);
	mlx_hook(assets.mlx.mlx_window, 17, 0, close_window, &assets);
	mlx_loop(assets.mlx.mlx_ptr);
	return (0);
}
