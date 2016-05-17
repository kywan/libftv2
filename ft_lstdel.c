/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:22:45 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/12 13:45:01 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next;

	if (*alst)
	{
		next = (*alst)->next;
		if (next)
			ft_lstdel(&next, del);
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
