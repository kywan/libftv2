/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:18:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 10:21:42 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_back(t_list **lst, t_list *item)
{
	if (!*lst)
		*lst = item;
	else
		ft_lstlast(*lst)->next = item;
	return (item);
}
