/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:33:22 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 11:21:14 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <wchar.h>

char	*ft_strdup(const char *c)
{
	int		i;
	char	*dst;

	i = 0;
	if (!c)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(c) + 1);
	if (dst)
	{
		while (c[i])
		{
			dst[i] = c[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

wchar_t	*ft_strdupwchar(const wchar_t *c)
{
	int		i;
	wchar_t	*dst;

	i = 0;
	if (!c)
		return (NULL);
	dst = (wchar_t *)malloc(sizeof(wchar_t) * ft_strlenwchar(c) + 1);
	if (dst)
	{
		while (c[i])
		{
			dst[i] = c[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
