/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:23:46 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 18:52:48 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				p;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	p = 0;
	while (p < n)
	{
		d[p] = s[p];
		if (d[p] == (unsigned char)c)
			return (dest + p + 1);
		p++;
	}
	return (NULL);
}
