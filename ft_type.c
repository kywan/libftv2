/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:29:00 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 16:03:35 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_error.h>
#include <libft.h>
#include <ft_printf.h>

static int	ft_cast(t_module *m, va_list *args)
{
	const char	*_signed = "di";
	const char	*_unsigned = "ouxX";
	
	if (ft_strchr(_signed, m->type) && ft_strcmp(m->modif, "l") == 0)
		return (ft_long(m, args));
	else if(ft_strchr(_signed, m->type) && (ft_strcmp(m->modif, "ll") == 0
				|| m->modif[0] == 'j'))
		return (ft_longlong(m, args));
	else if ((ft_strchr(_signed, m->type) && (m->modif[0] == '\0'
					|| m->modif[0] == 'h')) || m->type == 'c') //prend en compte modif h et hh
		return (ft_int(m, args));
	else if(ft_strchr(_unsigned, m->type) && ft_strcmp(m->modif, "l") == 0)
		return (ft_ulong(m, args));
	else if(ft_strchr(_unsigned, m->type) && (ft_strcmp(m->modif, "ll") == 0
				|| m->modif[0] == 'j'))
		return (ft_ulonglong(m, args));
	else if ((ft_strchr(_unsigned, m->type) && (m->modif[0] == '\0'
					|| m->modif[0] == 'h')) || m->type == 'c')
		return (ft_uint(m, args));
	else if ((ft_strchr(_signed, m->type) || ft_strchr(_unsigned, m->type))
			&& m->modif[0] == 'z')
		return (ft_sizet(m, args));
	else
	{
		ft_display_error(badmodif, m);
		return (-1);
	}
}

static int	ft_other_type(t_module *module)
{
	int	i;

	i = module->width;
	if (module->flag.moins)
		ft_putchar(module->type);
	while (i > 0)
	{
		if (module->flag.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
		ft_putchar(module->type);
	return (module->width + 1);
}

int	ft_valid_type(t_module *module, va_list *args)
{
	char *map = "sSpdDioOuUxXcC";

	if (ft_strchr(map, module->type))
	{
		return (ft_cast(module, args));
	}
	else
		return (ft_other_type(module));
}
