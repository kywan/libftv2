/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 15:49:13 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

int	ft_long_init(t_module *m, long long val, int base, char *base_str)
{
	int		i;

	m->val_str = ft_i128toa((val < 0 ? val * -1 : val), base, base_str);
	m->val_len = ft_strlen(m->val_str);
	m->width -= m->prec > 0 ? m->prec : m->val_len;
	m->prec = m->prec > 0 ? m->prec - m->val_len : -1;
	i = m->width;
	if (m->flag.plus || m->flag.space || val < 0)
		i--;
	return (i);

}

int	ft_ulong(t_module *m, va_list args)
{
	__int128	val;
	int			i;

	val = (__int128)va_arg(args, unsigned long);
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
	i = ft_long_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (ft_int_moins(m, val, i, m->prec));
	else
		return (ft_int_nmoins(m, val, i, m->prec));
}
