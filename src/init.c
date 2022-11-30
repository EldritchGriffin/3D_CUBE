/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:15:04 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/30 00:29:17 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// temporary functions until a map parser is created.
char    **get_map(t_lvl *lvl)
{
	char    **map;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
    

	tmp1 = get_next_line(lvl->fd);
	while(1)
	{
		tmp2 = get_next_line(lvl->fd);
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
    mlx->w_h = P_H * SSCL;
    mlx->w_w = P_W * SSCL;
    mlx->mp = mlx_init();
    mlx->w3 = mlx_new_window(mlx->mp, mlx->w_w, mlx->w_h, "CUB3D MADAFAKA");
}

void    level_init(t_lvl   *lvl)
{
    //further coding required after the map is parsed;
    lvl->map = get_map(lvl);
    lvl->l_w = ft_strlen(lvl->map[0]);
    lvl->l_h = count_height(lvl->map);
}

void    plyr_init(t_ply *ply, t_lvl *lvl)
{
    ply->fov = 60;
    ply->p_alt = UNIT / 2;
    ply->pa = 270;
    ply->p_pos = malloc(sizeof(t_pos));
    p_pos_init(ply->p_pos, lvl);
}

void    img_init(t_data *data)
{
    data->wrld->img = mlx_new_image(data->mlx->mp, data->mlx->w_w, data->mlx->w_h);
    data->wrld->addr = mlx_get_data_addr(data->wrld->img, &data->wrld->bpp, &data->wrld->len, &data->wrld->endn);
    data->minimp->img = mlx_new_image(data->mlx->mp,data->mlx->w_w, data->mlx->w_h);
    data->minimp->addr = mlx_get_data_addr(data->minimp->img, &data->minimp->bpp, &data->minimp->len, &data->minimp->endn);
    data->floor->img = mlx_new_image(data->mlx->mp, data->mlx->w_w, data->mlx->w_h / 2);
	data->floor->addr = mlx_get_data_addr(data->floor->img, &data->floor->bpp, &data->floor->len, &data->floor->endn);
    data->ceiling->img = mlx_new_image(data->mlx->mp, data->mlx->w_w, data->mlx->w_h / 2);
	data->ceiling->addr = mlx_get_data_addr(data->ceiling->img, &data->ceiling->bpp, &data->ceiling->len, &data->ceiling->endn);
}

t_data  *get_data(int ac, char **av)
{
    t_data  *data;

    ft_init_data(&data); 
    if (!file_check(av[1], &data->lvl)) 
        return(NULL);
    if (!is_filevalid(data))
        return (printf("Invalide file format!\n"), NULL);
    printf("%d\n", data->lvl->cco);
    printf("%d\n", data->lvl->fco);
    
    level_init(data->lvl);
    init_mlx(data->mlx, data->lvl);
    plyr_init(data->ply, data->lvl);
    img_init(data);
    data->dsp = ((data->mlx->w_w / 2) / tanf(deg_to_rad(data->ply->fov / 2))) - 700;
    data->abr =  data->ply->fov / data->mlx->w_w;
    return (data);
}