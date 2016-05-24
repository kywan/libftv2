/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 11:38:40 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>

int	ft_string(t_module *module, va_list args)
{
	int		i;
	int		len;
	char	*value;

	i = module->width - 1;
	value = ft_strdup(va_arg(args, char*));
	len = ft_strlen(value);
	if (module->flag.moins)
		module->prec >= 0 ? ft_putstrlen(value, module->prec) : ft_putstr(value);
	while (i > len)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
		module->prec >= 0 ? ft_putstrlen(value, module->prec) : ft_putstr(value);
	free(value);
	return (module->width > module->prec ? module->width : module->prec);
}
