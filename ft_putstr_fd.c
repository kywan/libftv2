/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:16:24 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 15:57:33 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char const *c, int fd)
{
	return (write(fd, c, ft_strlen(c)));
}

int	ft_putstrlen_fd(char const *c, int len, int fd)
{
	if (len > (int)ft_strlen(c))
		len = ft_strlen(c);
	return ((int)write(fd, c, len));
}
