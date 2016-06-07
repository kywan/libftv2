/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/07 16:06:37 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

int	ft_ulong(t_module *m, va_list args)
{
	intmax_t	val;
	int			i;

	val = (intmax_t)va_arg(args, unsigned long);
	i = ft_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}

int	ft_long(t_module *m, va_list args)
{
	intmax_t	val;
	int			i;

	val = (intmax_t)va_arg(args, long);
	i = ft_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}
