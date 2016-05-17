/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 14:44:59 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>

int	ft_sizet(t_module *module, va_list *args)
{
	size_t	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (size_t *)malloc(sizeof(size_t));
	*tmp = (size_t)va_arg(*args, size_t);
	return (1);
}
