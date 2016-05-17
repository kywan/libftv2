/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:33:03 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/22 13:07:22 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	ft_check_width(char *str, t_module *module)
{
	int	i;
	int	width;

	i = 0;
	width = ft_atoi(str);
	module->width = width;
	if (width > 0)
		i++;
	while ((width /= 10) > 0)
		i++;
	return (i);
}
