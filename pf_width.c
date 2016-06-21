/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:33:03 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 16:09:24 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

int	pf_check_width(char *str, t_module *module)
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
	if (*str == '*')
	{
		module->width = -2;
		i++;
	}
	return (i);
}
