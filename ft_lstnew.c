/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:31:04 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:43:59 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*x;
	unsigned char	*new_content;

	if (!(x = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if ((new_content = (unsigned char *)malloc(content_size)))
		{
			ft_memcpy((void *)new_content, content, content_size);
			x->content = (void *)new_content;
		}
		if (content_size)
			x->content_size = content_size;
		else
			x->content_size = 0;
	}
	else
		x->content = NULL;
	x->next = NULL;
	return (x);
}
