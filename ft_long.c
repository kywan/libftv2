/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 14:39:35 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>

int	ft_ulong(t_module *module, va_list *args)
{
	unsigned long	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (unsigned long *)malloc(sizeof(unsigned long));
	*tmp = (unsigned long)va_arg(*args, unsigned long);
	return (1);
}

int	ft_long(t_module *module, va_list *args)
{
	long	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (long *)malloc(sizeof(long));
	*tmp = (long)va_arg(*args, long);
	return (1);
}
