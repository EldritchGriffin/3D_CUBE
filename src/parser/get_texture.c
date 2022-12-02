/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:16:50 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:17:27 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


bool    init_texture(char *str, t_data *data, int flag)
{
    char *tmp;


    tmp = NULL;  
    tmp = ft_strtrim(str, " \n");
    if (!tmp)
        exit(1); ///-----still need to add a free fucntion
    if (flag == NO && check_no(tmp, data))
        return (data->lvl->no = tmp, true);
    else if (flag == SO && check_so(tmp, data))   
       return (data->lvl->so = tmp, true);
    else if (flag == WE && check_we(tmp, data))
        return (data->lvl->we = tmp, true);
    else if (flag == EA && check_ea(tmp, data))
        return (data->lvl->ea = tmp, true);
    free(tmp);
    ft_putendl_fd("Update a valid pathname!", STDERR);
    return (false);
}
