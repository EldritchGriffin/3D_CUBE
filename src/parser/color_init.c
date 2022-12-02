/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:08:21 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:08:36 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int       init_color(t_data *data)
{
    return ((data->lvl->r << 16) | (data->lvl->g << 8) | data->lvl->b );        
}

bool   init_ceiling(char *str , t_data *data)
{
    char *tmp;
    char **colors;
    int color;
    int i;
    
    i = -1;
    tmp = NULL;         
    tmp = ft_strtrim(str," \n");
    if (!tmp)
        exit(1);//---------
    if (!check_colors(str))
        return (false);
    colors = ft_split(tmp, ',');
    while (colors[++i])
    {   
        color = atoi(colors[i]);
       if (!check_color(i, data, color))
            return (false);
    }
    return (true);
}