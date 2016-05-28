/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/27 18:09:28 by pgrassin         ###   ########.fr       */
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
	__int128	value;
	int	value_len;
	char	*value_str;
	int		i;

	value = (__int128)va_arg(args, long long);
	value_str = ft_i128toa(value, 10, "0123456789");
	value_len = ft_strlen(value_str);
	module->prec > 0 ? module->width -= module->prec : module->width;
	module->prec > 0 ? module->prec -= value_len : module->prec;
	i = module->width - 1;
	if (module->flag.moins)
	{
		while (module->prec > 0)
		{
			ft_putchar('0');
			module->prec--;
		}
		ft_putstr(value_str);
	}
	while (i > value_len)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
	{
		while (module->prec > 0)
		{
			ft_putchar('0');
			module->prec--;
		}
		ft_putstr(value_str);
	}
	return (module->prec > 0 ? module->width + module->prec : module->width + value_len);
}
