/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:03:14 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 16:27:44 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

int	ft_hexaminus(t_module *m, va_list args)
{
	__int128	val;
	int			i;

	val = (__int128)va_arg(args, __int128);
	i = ft_int_init(m, val, 16, "0123456789abcdef");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}

int	ft_hexamax(t_module *m, va_list args)
{
	__int128	val;
	int			i;

	val = (__int128)va_arg(args, __int128);
	i = ft_int_init(m, val, 16, "0123456789ABCDEF");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}
