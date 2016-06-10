/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:52:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 17:04:13 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_display_error(int error, t_module *module)
{
	if (error == 0)
		ft_putstr("[error] : le flag '0' est incompatible avec le flag '-'\n");
	else if (error == 1)
		ft_putstr("[error] : le flag ' ' est incompatible avec le flag '+'\n");
	else if (error == 2)
	{
		ft_putstr("[error] : le type ");
		ft_putchar(module->type);
		ft_putstr(" n'est pas un type valide \n");
	}
	else if (error == 3)
	{
		ft_putstr("[error] : le type ");
		ft_putchar(module->type);
		ft_putstr(" n'est pas valide avec le modificateur ");
		ft_putendl(module->modif);
	}
	else
		ft_putstr("[error] une erreur inconue est survenue/n");
	return (-1);
}

int		ft_error(t_module *module)
{
	if (ft_valid_flag(module) != 0)
		return (-1);
	return(0);
}
