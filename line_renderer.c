/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:11:57 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/01 20:12:24 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int abs(int n) { return ((n > 0) ? n : (n * (-1))); }
 
void render_ray(int X0, int Y0, int X1, int Y1, t_data *data, int color)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(data->mlx->mp, data->mlx->w2, round(X), round(Y), color); 
        X += Xinc;
        Y += Yinc; 
    }
}