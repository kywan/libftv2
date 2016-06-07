/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/02 16:04:16 by pgrassin         ###   ########.fr       */
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
	int		total;
	int		ter;

	value = ft_strdup(va_arg(args, char*));
	len = ft_strlen(value);
	total = 0;
	if (module->flag.moins)
		total = module->prec >= 0 ? ft_putstrlen(value, module->prec) : ft_putstr(value);
	ter = (module->prec >= 0 && module->prec < len ? module->prec : len); // retirer la precision si elle est >= 0
	i = module->width - ter;
	module->width = i;
	while (i > 0/*(len > module->prec ? module->prec : len)*/)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
		total++;
	}
	if (!module->flag.moins)
		total += module->prec >= 0 ? ft_putstrlen(value, module->prec) : ft_putstr(value);
	free(value);
	return (total);
}
