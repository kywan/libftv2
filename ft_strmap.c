/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:20:51 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 18:54:55 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		s_len;
	char	*d;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * s_len + 1);
	if (d)
	{
		while (s[i])
		{
			d[i] = f(s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	return (NULL);
}
