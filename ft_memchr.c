/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:36:40 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:59:06 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				p;
	unsigned char		*x;

	x = (unsigned char *)str;
	p = 0;
	while (p < n)
	{
		if (x[p] == (unsigned char)c)
			return ((char *)x + p);
		p++;
	}
	return (0);
}
