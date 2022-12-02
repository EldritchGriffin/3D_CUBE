/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:39:15 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:26:23 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

bool    line_check(char *str, t_data *data, int *checker)
{   
    if (!ft_strncmp(str, "NO ", 3) && init_texture(str + 3, data, NO) \
            && isvalid(str + 3, "xpm"))
        return (printf("North file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "SO ", 3) && init_texture(str + 3, data, SO) \
            && isvalid(str + 3, "xpm"))
        return (printf("South file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "WE ", 3) &&  init_texture(str + 3, data, WE) \
            && isvalid(str + 3, "xpm"))
            return (printf("West file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "EA ", 3) && init_texture(str + 3, data, EA) \
             && isvalid(str + 3, "xpm"))
        return (printf("East file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "C ", 2) && init_ceiling(str + 2, data))
        return (data->lvl->cco = init_color(data), ++*checker,true);
     else if (!ft_strncmp(str, "F ", 2) && init_ceiling(str + 2, data))
        return (data->lvl->fco = init_color(data), ++*checker,true);
    return (false);
}

bool is_filevalid(t_data *data)
{
    char *str;
    int checker;

    checker = 0;
    str = NULL;
    data->lvl->map = NULL;
    init_varibles(&data->lvl);
    str = get_next_line(data->lvl->fd);
    while(str)
    {
        if (str[0] == '\n')
        {
            free(str);
            str = get_next_line(data->lvl->fd);
            continue ;
        }
        if (!line_check(str, data, &checker))   {
            if (checker != 6)   
                return (free(str), printf("str%s\n", str), false);
            else
            {
                printf("before get map\n");
                data->lvl->map = get_map(data, str);
                printf("map_len=====>%lu\n", map_width(&data->lvl));
                if (!data->lvl->map)
                    return (free(str),false);
                break ;
            }
        }
        free(str);
        str = get_next_line(data->lvl->fd);
    }
    if (checker == 6 && data->lvl->map)
        return (true);   
    return (false); 
}

