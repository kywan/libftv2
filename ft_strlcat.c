/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:11:52 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/02 13:03:48 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlcat(char *dest, char *src, size_t size)
{
	const size_t	dlen = ft_strlen(dest);
	const size_t	len = ft_strlen(src);
	size_t			p;

	if (size < dlen)
		return (len + size);
	dest += dlen;
	p = 0;
	while ((src[p]) && (p < size - dlen - 1))
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (len + dlen);
}
