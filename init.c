/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:15:04 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/01 23:10:04 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

//temporary functions until a map parser is created.
char    **get_map()
{
	char    **map;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	int fd	 = open("/Users/aelyakou/Desktop/cube3d/map.cub", O_RDWR);

	tmp1 = get_next_line(fd);
	while(1)
	{
		tmp2 = get_next_line(fd);
		if(tmp2 == NULL)
			break;
		tmp3 = tmp1;
		tmp1 = ft_strjoin(tmp1, tmp2);
		free(tmp3);
	}
	map = ft_split (tmp1, '\n');
	return (map);
}
void	print_map(char	**map)
{
	int i = 0;

	while (map[i])
		ft_putstr_fd(map[i++], 1), ft_putstr_fd("\n", 1);
}
int count_height(char   **map)
{
    int i = 0;

    while(map[i])
        i++;
    return (i);
}
//end of temporary functions.

void    p_pos_init(t_pos    *pos, t_lvl *lvl)
{
    int i;
    int j;

    i = 0;
    while(lvl->map[i])
    {
        j = 0;
        while(lvl->map[i][j])
        {
            if(lvl->map[i][j] == 'P')
            {
                pos->x = j * UNIT + (UNIT / 2);
                pos->y = i * UNIT + (UNIT / 2);
                return ;
            }
            j++;
        }
        i++;
    }
}

void    init_mlx(t_mlx    *mlx, t_lvl   *lvl)
{
    mlx->mp = mlx_init();
    mlx->w2 = mlx_new_window(mlx->mp, lvl->l_w * UNIT, lvl->l_h * UNIT, "CUB2D MADAFAKA");
    mlx->w3 = mlx_new_window(mlx->mp, lvl->l_w * UNIT, lvl->l_h * UNIT, "CUB3D MADAFAKA");
    // mlx->w3 = mlx_new_window(mlx->mp, P_W, P_H, "CUB3D MADAFAKA");
}

void    level_init(t_lvl   *lvl)
{
    //further coding required after the map is parsed;
    lvl->map = get_map();
    lvl->l_w = ft_strlen(lvl->map[0]);
    lvl->l_h = count_height(lvl->map);
}

void    plyr_init(t_ply *ply, t_lvl *lvl)
{
    ply->fov = 60;
    ply->p_alt = 32;
    ply->pa = 90;
    ply->p_pos = malloc(sizeof(t_pos));
    p_pos_init(ply->p_pos, lvl);
}

t_data  *get_data()
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    data->lvl = malloc(sizeof(t_lvl));
    data->mlx = malloc(sizeof(t_mlx));
    data->ply = malloc(sizeof(t_ply));
    level_init(data->lvl);
    init_mlx(data->mlx, data->lvl);
    plyr_init(data->ply, data->lvl);
    data->dsp = (P_W / 2) / tanf(deg_to_rad(data->ply->fov / 2));
    data->abr =  data->ply->fov / P_W;
    return (data);
}