/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 10:09:19 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>

int	ft_uint(t_module *module, va_list args)
{
	unsigned int	*tmp;

	module->flag.zero = 0; //a suprimer
	tmp = (unsigned int *)malloc(sizeof(int));
	*tmp = (unsigned int)va_arg(args, unsigned int);
	return (1);
}

int				ft_int(t_module *module, va_list args)
{
	int	value;
	int	value_len;
	char	*value_str;

	value = va_arg(args, int);
	value_str = ft_itoa(value);
	value_len = ft_strlen(value_str);
	module->width -= value_len;
	while (module->prec >= 0 || module->width > 0)
	{
		
	}
	return (1);
}
