/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:40:47 by aelyakou          #+#    #+#             */
/*   Updated: 2022/03/13 21:40:49 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(char	**level, int	*cc)
{
	t_vec2	v1;

	v1.i = 0;
	v1.j = 0;
	while (level[v1.i][v1.j])
	{
		if (level[v1.i][v1.j] == 'P' && level [v1.i - 1][v1.j] == 'C')
			*cc = *cc - 1;
		if ((level[v1.i][v1.j] == 'P' && level[v1.i - 1][v1.j] == 'E' &&
		*cc == 0) || (level[v1.i][v1.j] == 'P' && level[v1.i - 1][v1.j] == 'N'))
			exit (0);
		if (level[v1.i][v1.j] == 'P' && level [v1.i - 1][v1.j]
		!= '1' && level [v1.i][v1.j] != 'E')
		{
			level[v1.i - 1][v1.j] = 'P';
			level[v1.i][v1.j] = '0';
			return ;
		}
		v1.j++;
		if (level[v1.i][v1.j] == '\0' && level[v1.i + 1])
		{
			v1.j = 0;
			v1.i++;
		}
	}
}

void	move_down(char	**level, int	*cc)
{
	t_vec2	v1;

	v1.i = 0;
	v1.j = 0;
	while (level[v1.i][v1.j])
	{
		if (level[v1.i][v1.j] == 'P' && level [v1.i + 1][v1.j] == 'C')
			*cc = *cc - 1;
		if ((level[v1.i][v1.j] == 'P' && level[v1.i + 1][v1.j] == 'E' &&
		*cc == 0) || (level[v1.i][v1.j] == 'P' && level[v1.i + 1][v1.j] == 'N'))
			exit (0);
		if (level[v1.i][v1.j] == 'P' && level [v1.i + 1][v1.j]
		!= '1' && level [v1.i][v1.j] != 'E')
		{
			level[v1.i + 1][v1.j] = 'P';
			level[v1.i][v1.j] = '0';
			return ;
		}
		v1.j++;
		if (level[v1.i][v1.j] == '\0' && level[v1.i + 1])
		{
			v1.j = 0;
			v1.i++;
		}
	}
}

void	move_left(char	**level, int	*cc)
{
	t_vec2	v1;

	v1.i = 0;
	v1.j = 0;
	while (level[v1.i][v1.j])
	{
		if (level[v1.i][v1.j] == 'P' && level [v1.i][v1.j - 1] == 'C')
			*cc = *cc - 1;
		if ((level[v1.i][v1.j] == 'P' && level[v1.i][v1.j - 1] == 'E' &&
		*cc == 0) || (level[v1.i][v1.j] == 'P' && level[v1.i][v1.j - 1] == 'N'))
			exit (0);
		if (level[v1.i][v1.j] == 'P' && level [v1.i][v1.j - 1]
		!= '1' && level [v1.i][v1.j - 1] != 'E')
		{
			level[v1.i][v1.j - 1] = 'P';
			level[v1.i][v1.j] = '0';
			return ;
		}
		v1.j++;
		if (level[v1.i][v1.j] == '\0' && level[v1.i + 1])
		{
			v1.j = 0;
			v1.i++;
		}
	}
}

void	move_right(char	**level, int	*cc)
{
	t_vec2	v1;

	v1.i = 0;
	v1.j = 0;
	while (level[v1.i][v1.j])
	{
		if (level[v1.i][v1.j] == 'P' && level [v1.i][v1.j + 1] == 'C')
			*cc = *cc - 1;
		if ((level[v1.i][v1.j] == 'P' && level[v1.i][v1.j + 1] == 'E' &&
		*cc == 0) || (level[v1.i][v1.j] == 'P' && level[v1.i][v1.j + 1] == 'N'))
			exit (0);
		if (level[v1.i][v1.j] == 'P' && level [v1.i][v1.j + 1]
		!= '1' && level [v1.i][v1.j + 1] != 'E')
		{
			level[v1.i][v1.j + 1] = 'P';
			level[v1.i][v1.j] = '0';
			return ;
		}
		v1.j++;
		if (level[v1.i][v1.j] == '\0' && level[v1.i + 1])
		{
			v1.j = 0;
			v1.i++;
		}
	}
}

int	increment_position(t_assets *a)
{
	t_vec2				v1;
	static t_vec2		v2;
	static int			status;
	char				*str;

	v1.i = -1;
	while (a->level[++v1.i])
	{	
		v1.j = -1;
		while (a->level[v1.i][++v1.j])
		{
			if ((v2.j != v1.j || v2.i != v1.i)
				&& a->level[v1.i][v1.j] == 'P' && status)
				return (status = 0, str = ft_itoa(a->mv++), mlx_string_put
					(a->m.mp, a->m.mw, 0, 0, 255, str), free(str), 0);
			if (a->level[v1.i][v1.j] == 'P')
			{
				str = ft_itoa(a->mv - 1);
				return (status = 1, v2.j = v1.j, v2.i = v1.i, mlx_string_put
					(a->m.mp, a->m.mw, 0, 0, 255, str), free(str), 0);
			}
		}
	}
	return (0);
}
