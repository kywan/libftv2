/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:52:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/17 11:39:00 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_error.h>
#include <libft.h>
#include <ft_printf.h>

int	ft_display_error(int error, t_module *module)
{
	if (error == incompflag_zeromoins)
		ft_putstr("[error] : le flag '0' est incompatible avec le flag '-'\n");
	else if (error == incompflag_spaceplus)
		ft_putstr("[error] : le flag ' ' est incompatible avec le flag '+'\n");
	else if (error == invalid_type)
	{
		ft_putstr("[error] : le type ");
		ft_putchar(module->type);
		ft_putstr(" n'est pas un type valide \n");
	}
	else if (error == badmodif)
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
	if (ft_valid_flag(module) != no_error)
		return (-1);
	return(no_error);
}
