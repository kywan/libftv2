/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:18:10 by pgrassin          #+#    #+#             */
/*   Updated: 2016/09/12 14:25:16 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t			ft_strsplit_len(const char *str, char c)
{
	size_t		counter;

	counter = 0;
	while ((*str) && (*str != c) && (str++))
		counter++;
	return (counter);
}

static size_t			ft_strsplit_count(const char *str, char c)
{
	size_t	len;

	len = 0;
	while ((*str) && (++len))
	{
		while (*str == c)
			str++;
		if (!*str)
			return (len + 1);
		else
			str++;
	}
	return (len + 1);
}

char					**ft_strsplit(const char *str, char s)
{
	char	**split;
	size_t	len;
	size_t	space;

	if (!(split = (char **)malloc(sizeof(char *) * ft_strsplit_count(str, s))))
		return (NULL);
	space = 0;
	while (*str)
	{
		while (*str == s)
			str++;
		if (*str)
		{
			len = ft_strsplit_len(str, s);
			split[space++] = ft_strsub(str, 0, len);
			str += len;
		}
	}
	split[space] = 0;
	return (split);
}
