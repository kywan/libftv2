/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:52:29 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/12 14:50:39 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*x;
	t_list	*result;

	result = 0;
	x = lst;
	while (x)
	{
		if (!ft_lst_push_back(&result, f(x)))
			return (NULL);
		x = x->next;
	}
	return (result);
}
