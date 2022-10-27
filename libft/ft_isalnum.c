/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:25 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/06 12:08:52 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else if (((i >= 'A') && (i <= 'Z')) || ((i >= 'a') && (i <= 'z')))
		return (1);
	else
		return (0);
}
