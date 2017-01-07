/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:59:51 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/24 15:59:06 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>
#include <stdint.h>

int		pf_uint(t_module *m, va_list args, int fd)
{
	intmax_t	val;
	int			i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (intmax_t)va_arg(args, unsigned int);
	if (m->type == 'O' || m->type == 'o')
		i = pf_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = pf_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = pf_int_init(m, val, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}

int		pf_uint32(t_module *m, va_list args, int fd)
{
	intmax_t	val;
	int			i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (intmax_t)va_arg(args, uint32_t);
	if (m->type == 'O' || m->type == 'o')
		i = pf_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = pf_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = pf_int_init(m, val, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}

int		pf_uint64(t_module *m, va_list args, int fd)
{
	intmax_t	val;
	int			i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (intmax_t)va_arg(args, uint64_t);
	if (m->type == 'O' || m->type == 'o')
		i = pf_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = pf_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = pf_int_init(m, val, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}
