/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:20:36 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/14 17:21:36 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strsub_len(char const *s, char c)
{
	int i;

	i = 0;
	while (*s && *s != c && *s++)
		i++;
	return (i);
}
