/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:58:14 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/02 17:15:00 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

static t_module	*ft_lstlastt(t_module *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static t_module	*ft_lst_push(t_module **lst, t_module *item)
{
	if (!*lst)
		*lst = item;
	else
		ft_lstlastt(*lst)->next = item;
	return (item);
}
t_module	*ft_createelem(t_module **start)
{
	t_module	*new;

	if (!(new = (t_module *)malloc(sizeof(t_module))))
		return (NULL);
	new->flag.moins = 0;
	new->flag.plus = 0;
	new->flag.diese = 0;
	new->flag.space = 0;
	new->flag.zero = 0;
	new->width = 0;
	new->prec = -1;
	new->modif = (char *)malloc(sizeof(char) * 3);
	new->type = '\0';
	new->next = NULL;
	return (ft_lst_push(start, new));
}
