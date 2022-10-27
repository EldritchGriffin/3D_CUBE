/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelyakou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 02:48:06 by aelyakou          #+#    #+#             */
/*   Updated: 2021/11/18 02:48:07 by aelyakou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	if (!*lst)
		return ;
	temp = *lst;
	tmp = *lst;
	while (temp)
	{
		tmp = tmp->next;
		ft_lstdelone(temp, del);
		temp = tmp;
	}
	*lst = NULL;
}
