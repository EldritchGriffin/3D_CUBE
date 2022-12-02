/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:10:54 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:11:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

size_t map_width(t_lvl **map)
{
   size_t height;
   size_t width;
   size_t count;
   size_t reminder;
   
   reminder = 0;
   height = -1;
   while ((*map)->map[++height])
   {
        width = 0;
        count = 0;
        while ((*map)->map[height][++width])
                count++;
        if (count > reminder)
            reminder = count;
   }
    return (reminder);
}

size_t map_hieght(t_lvl *map)
{
    int i;
    size_t count;

    count = 0;
    i = -1;
    while(map->map[++i])
        count++;
    return (count);   
}