/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:12:55 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:16:16 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


bool is_player(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool check_last(char *str)
{
    return (str[ft_strlen(str) - 1] == '1' || str[ft_strlen(str) - 1] == ' '); 
}

bool check_first(char *str)
{
    return (str[0] == '1' || str[0] == ' '); 
}



bool validator(char c)
{
    return (c == ' ' || c == ',');
}

void    init_pos(char c, t_data *data)
{
    if (c == 'N')
        data->ply->pa  = N_ANGLE;
    else if (c == 'E')
        data->ply->pa = E_ANGLE;
    else if (c == 'W')
        data->ply->pa = W_ANGLE;
    else if (c == 'S')
        data->ply->pa = S_ANGLE;
}