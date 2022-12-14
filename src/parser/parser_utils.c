/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:53:29 by zrabhi            #+#    #+#             */
/*   Updated: 2022/11/29 21:17:35 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


bool    isvalid(char *av, char *str)
{
    int i;
    char **file;

    file = NULL;
    i = -1;
    file = ft_split(av, '.');
    while (file[++i])
    {
        if (!file[i + 1])
        {
            if (ft_strncmp(file[i], str, 3))
                return (free(file),false);
        }
    }   
    return (free(file),true);
}

bool    check_args(int ac, char *av)
{
    if (ac == 1)
    {
        red();
        ft_putendl_fd("Invalide arguments, please enter valide one's", STDERR);        
        return (false);    
    }
    else if (ac > 2)
    {
        red();
        ft_putendl_fd("To many arguments, You should enter : Executable file + \
             map file of your choice!", STDERR);
        return (false);
    }
    if (!isvalid(av, "cub"))
    {
        red();
        ft_putendl_fd("Map file should end whit .cub at end", STDERR);
        return (false);
    }
    return (true); 
}