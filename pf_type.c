/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:29:00 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 18:59:16 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

static int	pf_cast_signed(t_module *m, va_list args, int fd)
{
	if (m->width == -2)
		if ((m->width = va_arg(args, int)) < 0 && (m->flag.moins = 1))
			m->width *= -1;
	if (m->prec == -2)
		m->prec = va_arg(args, int);
	if (m->type == 'D')
		return (pf_uint64(m, args, fd));
	if (ft_strcmp(m->modif, "h") == 0)
		return (pf_short(m, args, fd));
	else if (ft_strcmp(m->modif, "hh") == 0)
		return (pf_schar(m, args, fd));
	else if (ft_strcmp(m->modif, "l") == 0)
		return (pf_long(m, args, fd));
	else if (ft_strcmp(m->modif, "ll") == 0)
		return (pf_longlong(m, args, fd));
	else if (ft_strcmp(m->modif, "j") == 0)
		return (pf_intmaxt(m, args, fd));
	else if (ft_strcmp(m->modif, "z") == 0)
		return (pf_sizet(m, args, fd));
	else if (m->type == 'D')
		return (pf_long(m, args, fd));
	else
		return (pf_int(m, args, fd));
}

static int	pf_cast_unsigned(t_module *m, va_list args, int fd)
{
	if (m->width == -2)
		if ((m->width = va_arg(args, int)) < 0)
		{
			m->width *= -1;
			m->flag.moins = 1;
		}
	if (m->prec == -2)
		m->prec = va_arg(args, int);
	if (m->type == 'o' && m->modif[0] == '\0')
		return (pf_uint32(m, args, fd));
	if (m->type == 'O' || ft_strcmp(m->modif, "l") == 0)
		return (pf_ulong(m, args, fd));
	if (ft_strcmp(m->modif, "h") == 0)
		return (pf_ushort(m, args, fd));
	else if (ft_strcmp(m->modif, "hh") == 0)
		return (pf_uchar(m, args, fd));
	else if (ft_strcmp(m->modif, "ll") == 0)
		return (pf_ulonglong(m, args, fd));
	else if (ft_strcmp(m->modif, "j") == 0)
		return (pf_uintmaxt(m, args, fd));
	else if (ft_strcmp(m->modif, "z") == 0)
		return (pf_ulonglong(m, args, fd));
	else
		return (pf_uint(m, args, fd));
}

static int	pf_other_type(t_module *module, va_list args, int fd)
{
	int	i;

	if (module->width == -2)
		if ((module->width = va_arg(args, int)) < 0)
		{
			module->width *= -1;
			module->flag.moins = 1;
		}
	if (module->prec == -2)
		module->prec = va_arg(args, int);
	i = module->width - 1;
	if (module->flag.moins)
		ft_putchar_fd(module->type, fd);
	while (i > 0)
	{
		if (module->flag.zero && !module->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
	if (!module->flag.moins)
		ft_putchar_fd(module->type, fd);
	return (module->width > 0 ? module->width : 1);
}

static int	pf_cast_string(t_module *m, va_list args, int fd)
{
	if (m->width == -2)
		if ((m->width = va_arg(args, int)) < 0)
		{
			m->width *= -1;
			m->flag.moins = 1;
		}
	m->prec == -2 ? m->prec = va_arg(args, int) : 0;
	if ((m->type == 'C')
			|| (m->type == 'c' && ft_strcmp(m->modif, "l") == 0))
		return (pf_wint(m, args, fd));
	else if (m->type == 'c')
		return (pf_char(m, args, fd));
	else if ((m->type == 'S')
			|| (m->type == 's' && ft_strcmp(m->modif, "l") == 0))
		return (pf_winchart(m, args, fd));
	else if (m->type == 's')
		return (pf_string(m, args, fd));
	else if (m->type == 'p' && (m->flag.diese = 1))
		return (pf_ulong(m, args, fd));
	else if (m->type == 'U')
		return (pf_ulong(m, args, fd));
	else
		return (pf_other_type(m, args, fd));
}

int			pf_valid_type(t_module *module, va_list args, int fd)
{
	const char	*csigned = "diD";
	const char	*cunsigned = "oOuxX";
	const char	*cstring = "cCsSpU";

	if (module->type == '\x00')
		return (0);
	else if (ft_strchr(csigned, module->type))
		return (pf_cast_signed(module, args, fd));
	else if (ft_strchr(cunsigned, module->type))
		return (pf_cast_unsigned(module, args, fd));
	else if (ft_strchr(cstring, module->type))
		return (pf_cast_string(module, args, fd));
	else
		return (pf_other_type(module, args, fd));
}
