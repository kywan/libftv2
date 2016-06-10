/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:59:51 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 17:58:38 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

int		ft_uint(t_module *m, va_list args)
{
	intmax_t	val;
	int			i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (intmax_t)va_arg(args, unsigned int);
	if (m->type == 'O' || m->type == 'o')
		i = ft_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = ft_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = ft_int_init(m, val, 16, "0123456789ABCDEF");
	else
	i = ft_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}
