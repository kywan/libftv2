/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:24:28 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 16:04:29 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s1);
	d = (char *)malloc(sizeof(char) * s_len + ft_strlen(s2) + 1);
	if (d)
	{
		while (s1[i])
		{
			d[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			d[s_len + i] = s2[i];
			i++;
		}
		d[s_len + i] = '\0';
	}
	return (d);
}
