/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:39:15 by zrabhi            #+#    #+#             */
/*   Updated: 2022/11/30 16:46:56 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


size_t map_len(t_lvl **map)
{
   size_t height;
   size_t width;
   size_t count;
   size_t reminder;
   
   reminder = 0;
   height = -1;
   while ((*map)->map[++height])
   {
        width = 0;
        count = 0;
        while ((*map)->map[height][++width])
                count++;
        if (count > reminder)
            reminder = count;
   }
    return (reminder);
}


bool file_check(char *av, t_lvl **map)
{

    (*map)->fd = open(av, O_RDONLY);
    if ((*map)->fd == -1)
    {
        close((*map)->fd);
        red();
        ft_putendl_fd("There is no map, please update a valide map!", STDERR);
        return (false);
    }
    return (true);
}

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

bool    init_texture(char *str, t_data *data, int flag)
{
    char *tmp;


    tmp = NULL;  
    tmp = ft_strtrim(str, " \n");
    if (!tmp)
        exit(1); ///-----still need to add a free fucntion
    if (flag == NO && check_no(tmp, data))
        return (data->lvl->no = tmp, true);
    else if (flag == SO && check_so(tmp, data))   
       return (data->lvl->so = tmp, true);
    else if (flag == WE && check_we(tmp, data))
        return (data->lvl->we = tmp, true);
    else if (flag == EA && check_ea(tmp, data))
        return (data->lvl->ea = tmp, true);
    free(tmp);
    ft_putendl_fd("Update a valid pathname!", STDERR);
    return (false);
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


bool   init_ceiling(char *str , t_data *data)
{
    char *tmp;
    char **colors;
    int color;
    int i;
    
    i = -1;
    tmp = NULL;         
    tmp = ft_strtrim(str," \n");
    if (!tmp)
        exit(1);//---------
    colors = ft_split(tmp, ',');
    while (colors[++i])
    {   
        color = atoi(colors[i]);
       if (!check_color(i, data, color))
            return (false);
    }
    return (true);
}


int       init_color(t_data *data)
{
    return ((data->lvl->r << 16) | (data->lvl->g << 8) | data->lvl->b );        
}

bool    line_check(char *str, t_data *data, int *checker)
{
    // if (!str)
    //     return (false);
    if (!ft_strncmp(str, "NO ", 3) && init_texture(str + 3, data, NO) \
            && isvalid(str + 3, "xpm"))
        return (printf("North file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "SO ", 3) && init_texture(str + 3, data, SO) \
            && isvalid(str + 3, "xpm"))
        return (printf("South file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "WE ", 3) &&  init_texture(str + 3, data, WE) \
            && isvalid(str + 3, "xpm"))
            return (printf("West file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "EA ", 3) && init_texture(str + 3, data, EA) \
             && isvalid(str + 3, "xpm"))
        return (printf("East file found\n"), ++*checker, true);
    else if (!ft_strncmp(str, "C ", 2) && init_ceiling(str + 2, data))
        return (data->lvl->cco = init_color(data), ++*checker,true);
     else if (!ft_strncmp(str, "F ", 2) && init_ceiling(str + 2, data))
        return (data->lvl->fco = init_color(data), ++*checker,true);
    return (false);
}

bool check_ismap(char *str)
{
    int i;

    i = -1;
    if(!str)
        return (false);
    while (str[++i])
    {
        if (str[i] == '1' || str[i] == '0')
            return (true);
    }
    return (false);
}

void    init_varibles(t_lvl **lvl)
{
    (*lvl)->n = 0;
    (*lvl)->e = 0;
    (*lvl)->w = 0;
    (*lvl)->s = 0;
} 




bool first_line(char *str)
{
    int i;
    i = -1;
    while (str[++i])
    {
        if (str[i] != '1' && str[i] != ' ')
            return (false); 
    }
    return (true);    
}

char    **get_map(t_lvl *lvl, char *str)
{
	char    **map;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;
	char	*tmp3 = NULL;
    
    tmp2 = ft_strtrim(str, "\n");
    if (!first_line(tmp2))
        printf("it s ttruee\n"), exit(1);
    
    while ()
	map = ft_split (tmp1, '\n');
	return (map);
}

// bool    map_checker(t_data *data)
// {
//     char *str;

//     str = get_next_line(data->lvl->fd);
//     printf("%s\n", str);


    
// }

bool is_filevalid(t_data *data)
{
    char *str;
    int checker;

    checker = 0;
    str = NULL;
    init_varibles(&data->lvl);
    str = get_next_line(data->lvl->fd);
    while(str)
    {
        if (str[0] == '\n')
        {
            printf("im here\n");
            free(str);
            str = get_next_line(data->lvl->fd);
            continue ;
        }
        if (!line_check(str, data, &checker))   {
            if (checker != 6)   
                return (free(str), printf("str%s\n", str), false);
            else
            {
                data->lvl->map = get_map(data->lvl, str);
                // free(str);
                break ;
            }
        }
        free(str);
        str = get_next_line(data->lvl->fd);
    }
    
    return (true);    
}

