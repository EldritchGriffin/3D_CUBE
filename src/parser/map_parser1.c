/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:11:32 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/02 22:16:43 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

bool newline_check(char *str)
{
    int i;
    
    i = 0;
    while(str[i] && str[i + 1])
    {
        if (str[i] == '\n' && str[i + 1] == '\n')
            return (printf("its true\n\n"), true);
        if (str[i] == '\n' && (str[i + 1] == '\t' || str[i + 1] == ' '))
        {
            while(str[++i] == ' ');
            if (str[i] == '\n')
                return (printf("new_line found!!"), true);      
        }
        i++;
    }
    return (false);
}

bool first_line(char *str)
{
    int i;
    i = -1;
    while (str[++i])
    {
        if (str[i]!= '1' && str[i] != ' ' )
        {
            if (str[i] != '\n' && str[i + 1 ] != 0)
                return (false);     
        }
    }
    return (true);    
}

bool issournded(int i, int j, char **map)
{   
   if (!check_first(map[i]) || !check_last(map[i]))
            return (false);
   if (map[i][j] == '0' || is_player(map[i][j]))
   {
        if (map[i][j + 1] == ' ' || map[i][j -1] == ' ')
                return (printf("1\n"), false);
        else if(j > ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
            return (printf("2\n"),false);
        else if(j > ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')
                return (printf("3\n"),false);
   }
//    if (!is_player(map[i][j]))
//     return (printf("here\n\n\n\n"), false);
   return (true);
}

static void    fill_with_zeros(char **map, int i)
{
    *map[i] = '0';
}



bool check_map(char **map, t_data *data)
{
    int i;
    int j;
    int checker;

    checker = 0;
    i = -1;        
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
             
            if (!issournded(i, j, map))
                return (printf("%dindex===>%d, char===>%c\n", i, j, map[i][j]), false);
            if (is_player(map[i][j]))
            {
                init_pos(map[i][j], i, j ,data);
                checker++;
            }
            if (map[i][j] == ' ')
                map[i][j] = '0';
        }    
    }
    if (checker > 1 )
        return(printf("to many players\n"), false);
    return (true);
}

char    **get_map(t_data *data, char *str)
{
	char    **map;
	char	*tmp1 = NULL;
	char	*tmp2 = NULL;
	char	*tmp3 = NULL;
    
    tmp2 = str;
    if (!first_line(tmp2))
        exit(1); //----
	while(1)
	{
		tmp3 = tmp1;
		tmp1 = ft_strjoin(tmp1, tmp2);
		free(tmp3);
        free(tmp2);
		tmp2 = get_next_line(data->lvl->fd);
		if (tmp2 == NULL)
			break;
	}
    if (newline_check(tmp1))
        exit(1);
	map = ft_split (tmp1, '\n');
    if (!check_map(map, data))
        exit(1); //--- free all data beforing exitting
	return (map);
}