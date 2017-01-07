/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:35:35 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:56:13 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src)
		return (dest);
	if ((dest < src) || (dest > src + n))
		return (ft_memcpy(dest, src, n));
	d = dest;
	s = src;
	while (n--)
		d[n] = s[n];
	return (dest);
}
