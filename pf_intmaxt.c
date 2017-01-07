/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_intmaxt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:30:23 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 16:25:36 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

int	pf_uintmaxt(t_module *m, va_list args, int fd)
{
	uintmax_t	val;
	int			i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (uintmax_t)va_arg(args, uintmax_t);
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

int	pf_intmaxt(t_module *m, va_list args, int fd)
{
	intmax_t	val;
	int			i;

	val = (intmax_t)va_arg(args, intmax_t);
	i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}
