/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:20:35 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/01 20:21:08 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

float   rad_to_deg(float    x)
{
    float res;

    res = x * 180 / PI;
    return (res);
}

float deg_to_rad(float  x)
{
    float res;

    res = x * PI / 180;
    return (res);
}