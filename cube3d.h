/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:59 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/01 22:55:48 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H
#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <string.h>


//here im defining constants that we'll be using through the program ;; (((im gonna explain what the projection plane is when ur here its kinda abstract)));;;
#define UNIT	64			//HOW MANY PIXELS IN EACH GRID UNIT; (( grid unit is the size dimensions of the cubes we're drawing  ));;;
#define	P_W		320			//WIDTH OF THE PROJECTION PLANE;
#define	P_H		200			//HEIGHT OF THE PROJECTION PLANE;
#define PI		3.14159		//APPROXIMATE VALUE OF PI



//here goes our global variables -----------

//global variables --------------------


typedef struct s_mlx
{
	void    *mp; //mlx_pointer;
	void    *w2; //window_pointer to 2D rendering;
	void	*w3; //window_pointer to 3D rendering;
}               t_mlx;


typedef	struct	s_pos
{
	float		x; // ta hadi khsni nshr7alk albegra dzb ???
	float		y;
}				t_pos;

//player struct;
typedef struct  s_ply
{
	t_pos		*p_pos; // player position;
	float		fov; // field of view;
	float		p_alt; // player altitude/height;
	float		pa;		//player angle;
}               t_ply;

//------------t_lvl var description for dummies hhhhhh-------------
/*
l_w == level_width;
l_h == level_height;
cco = ceiling color;
fco = floor color;
no = north texture pathname;
so = south texture pathname;
we = west texture pathname;
ea = east texture pathname;
btw fill map empty spaces with 0s;
*/
typedef struct s_lvl
{
	char	**map;
	int		l_w;
	int		l_h;
	int		cco;
	int		fco;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_lvl;


//t_data is the struct we gonna assign all our other main structs into in main for ease of parameter passing; lghlid dzb;;
typedef struct	s_data
{
	t_lvl	*lvl;
	t_ply	*ply;
	t_mlx	*mlx;
	float	abr; //angle between rays;
	float	dsp; //distance between player and projection plane;

}				t_data;


//--------------level parsing functions----------------

char    **get_map();
t_data  *get_data();

//--------------level drawing functions----------------

//--------------math convrsion funcs-------------------

float   rad_to_deg(float    x);
float	deg_to_rad(float  x);
float   normalize_ray(float rl, float ra, t_data    *data);

//--------------raycasting funcs------------------------

float	cast_ray(t_data    *data, int i);
void	render_ray(int X0, int Y0, int X1, int Y1, t_data *data, int color);


#endif