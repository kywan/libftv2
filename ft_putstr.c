/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:23:02 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 10:19:07 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *c)
{
	write(1, c, ft_strlen(c));
}

void	ft_putstrlen(char const *c, int len)
{
	if (len > (int)ft_strlen(c))
		len = ft_strlen(c);
	write(1, c, len);
}
