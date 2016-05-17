/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:21:36 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 17:57:06 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	t;

	t = 0;
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d)
	{
		s += start;
		while (len > t)
		{
			d[t] = s[t];
			t++;
		}
		d[t] = '\0';
	}
	return (d);
}
