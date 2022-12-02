/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:10:54 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:33:33 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

size_t map_width(t_lvl *lvl)
{
   size_t height;
   size_t width;
   size_t count;
   size_t reminder;
   printf("im hehre\n");
   reminder = 0;
   height = -1;
   while (lvl->map[++height])
   {
        width = 0;
        count = 0;
        while (lvl->map[height][++width])
                count++;
        if (count > reminder)
            reminder = count;
   }
    return (reminder);
}

size_t map_hieght(t_lvl *lvl)
{

    printf("im hehre2\n");
    int i;
    size_t count;

    count = 0;
    i = -1;
    while(lvl->map[++i])
        count++;
    return (count);   
}