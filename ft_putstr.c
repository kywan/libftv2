/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:23:02 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 15:56:57 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr(char const *c)
{
	return ((int)write(1, c, ft_strlen(c)));
}

int	ft_putstrlen(char const *c, int len)
{
	if (len > (int)ft_strlen(c))
		len = ft_strlen(c);
	return ((int)write(1, c, len));
}
