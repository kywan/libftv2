/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:18:23 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 15:46:40 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

int		ft_short(t_module *m, va_list args)
{
	short	val;
	int			i;

	val = (short)va_arg(args, int);
	i = ft_int_init(m, (intmax_t)val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}

int		ft_ushort(t_module *m, va_list args)
{
	unsigned short	val;
	int				i;

	val = (unsigned short)va_arg(args,unsigned int);
	i = ft_int_init(m, (intmax_t)val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}
