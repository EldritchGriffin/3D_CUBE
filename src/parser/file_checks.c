/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:04:53 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 19:05:51 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


bool  check_no(char *str, t_data *data)
{
    data->lvl->n++;
    if (data->lvl->n > 1 )
        return (false);
    data->lvl->fd_n = open(str, O_RDONLY);
    if (data->lvl->fd_n == -1)
    {
        close(data->lvl->fd_n);
        red();
        ft_putendl_fd("North texture file not found!", STDERR);
        return (false);
    }
    return (close(data->lvl->fd_n),true);
}

bool  check_we(char *str, t_data *data)
{
    data->lvl->w++;
    if (data->lvl->w > 1 )
        return (false);
    data->lvl->fd_w= open(str, O_RDONLY);
    if (data->lvl->fd_w == -1)
    {
        close(data->lvl->fd_w);
        red();
        ft_putendl_fd("West texture file not found!", STDERR);
        return (false);
    }
            
    return (close(data->lvl->fd_w), true);
}

bool  check_ea(char *str, t_data *data)
{
    data->lvl->e++;
    if (data->lvl->e > 1 )
        return (false);
    data->lvl->fd_e = open(str, O_RDONLY);
    if (data->lvl->fd_e == -1)
    {
        close(data->lvl->fd_e);
        red();
        ft_putendl_fd("East texture file not found!", STDERR);
        return (false);
    }        
    return (close(data->lvl->fd_e), true);
}

bool  check_so(char *str, t_data *data)
{
    data->lvl->s++;
    if (data->lvl->s > 1 )
        return (false);
    data->lvl->fd_s = open(str, O_RDONLY);
    printf("%d\n", data->lvl->fd_s);
    if (data->lvl->fd_s == -1)
    {
        close(data->lvl->fd_s);
        red();
        ft_putendl_fd("South texture file not found!", STDERR);
        return (false);
    }
    return (close(data->lvl->fd_s), true);
}