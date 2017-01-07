/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:21:01 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 18:54:35 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	int		i;
	char	*d;

	s_len = ft_strlen(s);
	i = 0;
	d = (char *)malloc(sizeof(char) * s_len + 1);
	if (d)
	{
		while (s[i])
		{
			d[i] = f(i, s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
