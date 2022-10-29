/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:21:10 by aelyakou          #+#    #+#             */
/*   Updated: 2022/10/29 00:27:27 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float   p_grid_pos(float a)
{
    float res;
    float rounded;

    rounded = roundf(a);
    res = 0;
    if(a - 0.5 == (int)a)
        return (0.5);
    else if(rounded == (int)a)
        res = a - rounded;
    else if (rounded > (int)a)
        res = (a - rounded) + 1;
    return (res);
}

int get_dir(float   ra)
{
    int res;

    res = 0;
    if(ra == 0)
        return (res);
    if (ra > 180)
        res = -1;
    else if (ra < 180)
        res = 1;
    return (res);
}

float   check_wall_h(float ra, t_data   *data)
{
    float   xa;
    float   ya;
    int     dir;
    float   res;

    res = 0;
    dir = get_dir(ra);
    ya = UNIT * dir;
    xa = UNIT / tanf(rad_to_deg(ra));
    return (res);
}

// float   check_wall_v(float ra, t_data   *data)
// {

// }

float    cast_ray(t_data    *data, int i)
{
    float   h;
    // float   v;
    float   ra;

    //TODO this is a hardcoded approach need to create a get ray angle function when we get into rotation
    ra = 120 - (i * data->abr);
    h = check_wall_h(ra, data);
    // v = check_wall_v(ra, data);
    // if  (h > v)
    //     return (v);
    // else if (v > h)
    //     return (h);
    // else
    //     return (h);
    return (h);
}