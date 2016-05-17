/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 14:39:08 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>
int	ft_ulonglong(t_module *module, va_list *args)
{
	unsigned long long	*tmp;


	module->flag.zero = 0; //a suprimer
	tmp = (unsigned long long *)malloc(sizeof(unsigned long long));
	*tmp = (unsigned long long)va_arg(*args, unsigned long long);
	return (1);
}
int	ft_longlong(t_module *module, va_list *args)
{
	long long	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (long long *)malloc(sizeof(long long));
	*tmp = (long long)va_arg(*args, long long);
	return (1);
}
