/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:50:49 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:59:37 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int i)
{
	int		n;
	int		dest_len;

	n = 0;
	dest_len = ft_strlen(dest);
	while (n < i && src[n])
	{
		if (!(dest[n + dest_len] = src[n]))
			return (dest);
		n++;
	}
	dest[n + dest_len] = '\0';
	return (dest);
}
