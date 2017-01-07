/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:26:33 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 18:55:55 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t i)
{
	unsigned int n;

	n = 0;
	while (n < i && src[n])
	{
		dest[n] = src[n];
		n++;
	}
	while (n < i)
		dest[n++] = '\0';
	return (dest);
}
