/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:35:58 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/17 17:28:13 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_next(char c, t_module *module)
{
	if (module->modif[0] == c)
	{
		module->modif[1] = c;
		module->modif[2] = '\0';
		return (2);
	}
	module->modif[1] = '\0';
	return (1);
}

int	ft_check_modif(char *str, t_module *module)
{
	if (str[0] == 'h' || str[0] == 'l')
	{
		module->modif[0] = str[0];
		return (ft_check_next(str[1], module));
	}
	if (str[0] == 'j' || str[0] == 'z')
	{
		module->modif[0] = str[0];
		module->modif[1] = '\0';
		return (1);
	}
	module->modif[0] = '\0';
	return (0);
}
