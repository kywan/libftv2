/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:18:23 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 16:23:50 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

int		pf_short(t_module *m, va_list args, int fd)
{
	short	val;
	int		i;

	val = (short)va_arg(args, int);
	i = pf_int_init(m, (intmax_t)val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}

int		pf_ushort(t_module *m, va_list args, int fd)
{
	unsigned short	val;
	int				i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (unsigned short)va_arg(args, unsigned int);
	if (m->type == 'O' || m->type == 'o')
		i = pf_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = pf_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = pf_int_init(m, val, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(m, (intmax_t)val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}
