/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/17 14:30:59 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>

int	ft_string(t_module *module, va_list args)
{
	int		i;
	int		len;
	char	*value;

	i = module->width - 1;
	value = ft_strdup(va_arg(args, char*));
	len = ft_strlen(value);
	if (module->flag.moins)
		ft_putstr(value);
	while (i > len)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
		ft_putstr(value);
	free(value);
	return (module->width == 0 ? len : module->width);
}
