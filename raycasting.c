/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:21:10 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/03 02:19:12 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int get_dir_v(float   ra)
{
    int res;

    res = 0;
    if(ra == 0)
        return (res);
    if (ra > 180)
        res = 1;
    else if (ra < 180)
        res = -1;
    return (res);
}

int get_dir_h(float ra)
{
    int res;
    
    res = 0;
    if(ra == 90 || ra == 270)
        return (res);
    if(ra > 90 && ra < 270)
        return (res = -1, res);
    if(ra < 90 || ra > 270)
        res = 1;
    return (res);
}

float   get_hwy(t_data  *data, int dir)
{
    int wy;
    
    if(dir == -1)
    {
        wy = (floor(data->ply->p_pos->y / UNIT) * UNIT ) - 1;
    }
    if(dir == 1)
    {
        wy = (floor(data->ply->p_pos->y / UNIT) * UNIT) + UNIT;
    }
    return (wy);
}

float   get_vwx(t_data  *data, int dir)
{
    int wx;
    
    if(dir == -1)
    {
        wx = (floor(data->ply->p_pos->x / UNIT) * UNIT ) - 1;
    }
    if(dir == 1)
    {
        wx = (floor(data->ply->p_pos->x / UNIT) * UNIT) + UNIT;
    }
    return (wx);
}

t_pos   check_wall_h(float  *res, float ra, t_data   *data)
{
    float   xa;
    float   ya;
    int     dir;
    t_pos   wpos;

    *res = 0;
    dir = get_dir_v(ra);
    if(dir == 0)
        return (*res = INFINITY, wpos);
    ya = UNIT * dir;
    xa = ya / -tanf(deg_to_rad(ra));
    wpos.y = get_hwy(data, dir);
    wpos.x = data->ply->p_pos->x + (data->ply->p_pos->y - wpos.y) / tanf(deg_to_rad(ra));
     if((int)wpos.x/UNIT >= data->lvl->l_w || (int)wpos.x/UNIT <= 0)
        return (*res = INFINITY, wpos);
    while(data->lvl->map[(int)wpos.y/UNIT][(int)wpos.x/UNIT] != '1')
    {
        wpos.x += xa;
        wpos.y += ya;
        if((int)wpos.x/UNIT >= data->lvl->l_w || (int)wpos.x/UNIT <= 0)
            break;
    }
    *res = sqrtf(powf((data->ply->p_pos->x - wpos.x), 2) + powf((data->ply->p_pos->y - wpos.y), 2));
    return (wpos);
}

t_pos   check_wall_v(float  *res, float ra, t_data   *data)
{
    float xa;
    float ya;
    int   dir;
    t_pos wpos;

    *res = 0;
    dir = get_dir_h(ra);
    if(dir == 0)
        return (*res = INFINITY, wpos);
    xa = UNIT * dir;
    ya = xa * -tanf(deg_to_rad(ra));
    wpos.x = get_vwx(data, dir);
    wpos.y =  data->ply->p_pos->y + (data->ply->p_pos->x - wpos.x) * tanf(deg_to_rad(ra));
    if((int)wpos.y/UNIT >= data->lvl->l_h || (int)wpos.y/UNIT <= 0)
        return (*res = INFINITY, wpos);
    while(data->lvl->map[(int)wpos.y/UNIT][(int)wpos.x/UNIT] != '1')
    {
        wpos.x += xa;
        wpos.y += ya;
        if((int)wpos.y/UNIT >= data->lvl->l_h || (int)wpos.y/UNIT <= 0)
            return (*res = INFINITY, wpos);
    }
    *res = sqrtf(powf((data->ply->p_pos->x - wpos.x), 2) + powf((data->ply->p_pos->y - wpos.y), 2));
    return (wpos);
}

float    cast_ray(t_data    *data, int i)
{
    float   h;
    float   v;
    float   ra;
    t_pos   wposv;
    t_pos   wposh;

    h = INFINITY;
    v = INFINITY;
    //TODO this is a hardcoded approach need to create a get ray angle function when we get into rotation
    ra = 120 - (i * data->abr);

    //------------------//
    wposv = check_wall_v(&v, ra, data);
    wposh = check_wall_h(&h, ra, data);
    if(h > v)
    {
        render_ray(data->ply->p_pos->x, data->ply->p_pos->y, wposv.x, wposv.y, data, (255 << 0 * 8));
        return (normalize_ray(v, ra, data));
    }
    if(h < v)
    {
        render_ray(data->ply->p_pos->x, data->ply->p_pos->y, wposh.x, wposh.y, data, (255 << 2 * 8));
        return (normalize_ray(h, ra, data));
    }
    return (0);
}