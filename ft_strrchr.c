/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:55:15 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:53:44 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	while (s[--len])
	{
		if (s[len] == (unsigned char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
