/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:24:20 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 10:35:58 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_strlen(const char *c)
{
	int i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int		ft_strlenwchar(const wchar_t *c)
{
	int i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
