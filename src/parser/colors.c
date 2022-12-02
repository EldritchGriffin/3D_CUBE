/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:59:39 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:08:55 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	purple(void)
{
	ft_putstr_fd("\033[0;35m", STDERR);
}

void	red(void)
{
	ft_putstr_fd("\033[0;31m", STDERR);
}

bool check_colors(char *str)
{   
    int i;
    int checker; 
    
    i = 0;
    checker = 0;
    while(str[i])
    {
        if (str[i] == ' ' && !validator(str[i + 1]))
            return (false);
        if (str[i] == ',')
            checker++;
        i++;
    }
    if (checker > 2 || checker < 2)
        return (false);
    return (true);            
}

bool check_color(int w_data, t_data *data, int color)
{
    if ((color < 0 ||  color > 255) || w_data == 3)
        return (ft_putendl_fd("Color out of range!", STDERR), false);
    if (!w_data)
        data->lvl->r = color;
    else if (w_data == 1)
        data->lvl->g = color;
    else if (w_data == 2)
        data->lvl->b = color;
    return (true);
}