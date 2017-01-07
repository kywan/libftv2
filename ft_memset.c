/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:39:25 by pgrassin          #+#    #+#             */
/*   Updated: 2015/11/30 13:49:10 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int i, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)dst;
	while (n--)
		d[n] = i;
	return (dst);
}
