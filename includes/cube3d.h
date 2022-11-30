/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <aelyakou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:59 by aelyakou          #+#    #+#             */
/*   Updated: 2022/11/30 00:44:50 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H
#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include <string.h>
# include <stdbool.h>



#define STDERR 2 
#define NO 1
#define SO 2
#define WE 3
#define EA 4
//here im defining constants that we'll be using through the program ;; (((im gonna explain what the projection plane is when ur here its kinda abstract)));;;
#define UNIT	100			//HOW MANY PIXELS IN EACH GRID UNIT; (( grid unit is the size dimensions of the cubes we're drawing  ));;;
#define	P_W		320			//WIDTH OF THE PROJECTION PLANE;
#define	P_H		200			//HEIGHT OF THE PROJECTION PLANE;
#define PI		3.14159		//APPROXIMATE VALUE OF PI
#define	MVS		10			//movement speed of player
#define	TRS		5			//turning speed of player
#define	SSCL	6			//screen scaler == (P_W * SSCL && P_H * SSCL)
#define	MSCL	8			//MINIMAP SCALER == (SCREEN WIDTH / MSCL && SCREEN HEIGHT / MSCL)

//this whole struct is created as an optimization process, to avoid using mlx_put_pixel, because its damn slow, so we'll create our own.
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endn;
}				t_img;

typedef struct s_mlx
{
	void    *mp; //mlx_pointer;
	void	*w3; //window_pointer to 3D rendering;
	int		w_h;
	int		w_w;
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
	int 	fd;
	int		fd_s;
	int 	fd_w;
	int		fd_e;
	int		fd_n;
	int		r;
	int		g;
	int		b;
	unsigned int		cco;
	unsigned int		fco;
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
	float	*rays;
	t_img	*wrld;
	t_img	*minimp;
	t_img	*floor;
	t_img	*ceiling;

}				t_data;

//-----parsing part (colors)----------
void	purple(void);
void	red(void);

///-------parsin part (error check)
bool 	is_filevalid(t_data *data);
bool    init_texture(char *str, t_data *data, int flag);
bool    line_check(char *str, t_data *data, int *checker);
bool    file_check(char *av, t_lvl **map);
bool    isvalid(char *av, char *str);
bool    check_args(int ac, char *av);
size_t  map_len(t_lvl **map);


//--------------level parsing functions----------------
void	ft_init_data(t_data **data);
char    **get_map();
t_data  *get_data();

//-----------free fucntions
void    free_tab(char **tab);

//--------------level drawing functions----------------

//--------------math funcs-------------------

float   limit_angles(float ra);
float   rad_to_deg(float  x);
float	deg_to_rad(float  x);
float   normalize_ray(float rl, float ra, t_data    *data);

//--------------raycasting funcs------------------------

float	cast_ray(t_data    *data, int i);
void	render_ray(int X0, int Y0, int X1, int Y1, t_data *data, int color);

//-------------mlx_mods---------------------------------

void	pixel_put_img(t_img *img, int x, int y, int color);


#endif