/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:29:00 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 10:00:37 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

static int	pf_cast_signed(t_module *m, va_list args)
{
	if (ft_strcmp(m->modif, "h") == 0)
		return (pf_short(m, args));
	else if (ft_strcmp(m->modif, "hh") == 0)
		return (pf_schar(m, args));
	else if (ft_strcmp(m->modif, "l") == 0 || m->type == 'D')
		return (pf_ulong(m, args));
	else if (ft_strcmp(m->modif, "ll") == 0)
		return (pf_longlong(m, args));
	else if (ft_strcmp(m->modif, "j") == 0)
		return (pf_intmaxt(m, args));
	else if (ft_strcmp(m->modif, "z") == 0)
		return (pf_sizet(m, args));
	else
		return (pf_int(m, args));
}

static int	pf_cast_unsigned(t_module *m, va_list args)
{
	if (ft_strcmp(m->modif, "h") == 0)
		return (pf_ushort(m, args));
	else if (ft_strcmp(m->modif, "hh") == 0)
		return (pf_uchar(m, args));
	else if (ft_strcmp(m->modif, "l") == 0
			|| (m->type == 'o' && m->modif == NULL))
		return (pf_ulong(m, args));
	else if (ft_strcmp(m->modif, "ll") == 0)
		return (pf_ulonglong(m, args));
	else if (ft_strcmp(m->modif, "j") == 0)
		return (pf_uintmaxt(m, args));
	else if (ft_strcmp(m->modif, "z") == 0)
		return (pf_sizet(m, args));
	else
		return (pf_uint(m, args));
}

static int	pf_other_type(t_module *module)
{
	int	i;

	i = module->width - 1;
	if (module->flag.moins)
		ft_putchar(module->type);
	while (i > 0)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
		ft_putchar(module->type);
	return (module->width > 0 ? module->width : 1);
}

static int	pf_cast_string(t_module *m, va_list args)
{
	if ((m->type == 'C' && m->modif[0] == '\0')
			|| (m->type == 'c' && ft_strcmp(m->modif, "l") == 0))
		return (pf_wint(m, args));
	else if (m->type == 'c')
		return (pf_char(m, args));
	else if ((m->type == 'S' && m->modif[0] == '\0')
			|| (m->type == 's' && ft_strcmp(m->modif, "l") == 0))
		return (pf_winchart(m, args));
	else if (m->type == 's')
		return (pf_string(m, args));
	else if (m->type == 'p')
	{
		m->flag.diese = 1;
		return (pf_ulong(m, args));
	}
	else if (m->type == 'U')
		return (pf_ulong(m, args));
	else
		return (pf_other_type(m));
}

int			pf_valid_type(t_module *module, va_list args)
{
	const char	*csigned = "diD";
	const char	*cunsigned = "oOuxX";
	const char	*cstring = "cCsSpU";

	if (module->type == '\x00')
		return (0);
	else if (ft_strchr(csigned, module->type))
		return (pf_cast_signed(module, args));
	else if (ft_strchr(cunsigned, module->type))
		return (pf_cast_unsigned(module, args));
	else if (ft_strchr(cstring, module->type))
		return (pf_cast_string(module, args));
	else
		return (pf_other_type(module));
}
