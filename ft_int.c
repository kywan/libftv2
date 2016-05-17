/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 14:39:46 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>

int	ft_uint(t_module *module, va_list *args)
{
	unsigned int	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (unsigned int *)malloc(sizeof(int));
	*tmp = (unsigned int)va_arg(*args, unsigned int);
	return (1);
}

int				ft_int(t_module *module, va_list *args)
{
	int	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (int *)malloc(sizeof(int));
	*tmp = (int)va_arg(*args, int);
	return (1);
}
