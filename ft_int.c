/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/31 14:26:34 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdint.h>

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
	intmax_t	value;
	int	value_len;
	char	*value_str;
	int		i;
	int		total;

	total = 0;
	value = (intmax_t)va_arg(args, int);
	value_str = ft_imaxtoa((value < 0 ? value * -1 : value), 10, "0123456789");
	value_len = ft_strlen(value_str);
	module->prec = module->prec > 0 ? module->prec -= value_len : -1;
	module->width -= module->prec > 0 ? module->prec :  value_len;
	i = module->width;
	if (module->flag.plus || module->flag.space || value < 0)
		i--;
	if (module->flag.moins)
	{
		if (module->flag.plus || value < 0)
			total += value >= 0 ? ft_putchar('+') : ft_putchar('-');
		else if (module->flag.space && value >= 0)
			total += ft_putchar(' ');
		while (module->prec > 0)
		{
			total += ft_putchar('0');
			module->prec--;
		}
		total += ft_putstr(value_str);
	}
	if ((module->flag.plus || value < 0) && !module->flag.moins && module->flag.zero) // le cas du moins est gerrer au dessus
		total += value >= 0 ? ft_putchar('+') : ft_putchar('-');
	else if (module->flag.space && value >= 0 && !module->flag.moins && module->flag.zero)
		total += module->flag.space && value >= 0 ? ft_putchar(' ') : 0;
	while (i > 0)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
		total ++;
	}
	if (!module->flag.moins)
	{
		if ((module->flag.plus || value < 0) && !module->flag.moins && !module->flag.zero)
			total += value >= 0 ? ft_putchar('+') : ft_putchar('-');
		else if (module->flag.space && value >= 0 && !module->flag.moins && !module->flag.zero)
			total += module->flag.space && value >= 0 ? ft_putchar(' ') : 0;
		while (module->prec > 0)
		{
			total += ft_putchar('0');
			module->prec--;
		}
		total += ft_putstr(value_str);
	}

	return (total);
}
