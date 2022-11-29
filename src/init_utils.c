/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:56:09 by zrabhi            #+#    #+#             */
/*   Updated: 2022/11/29 14:58:41 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


void    ft_init_data(t_data **data)
{

    (*data) = malloc(sizeof(t_data));
    (*data)->lvl = malloc(sizeof(t_lvl));
    (*data)->mlx = malloc(sizeof(t_mlx));
    (*data)->ply = malloc(sizeof(t_ply));
    (*data)->minimp = malloc(sizeof(t_img));
    (*data)->wrld = malloc(sizeof(t_img));
    (*data)->floor = malloc(sizeof(t_img));
    (*data)->ceiling = malloc(sizeof(t_img));   
}