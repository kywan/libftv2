/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/18 15:26:08 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

static int		pf_int_diese(t_module *m, __int128 val)
{
	if (val != 0)
	{
		if (m->type == 'o' || m->type == 'O')
			return (ft_putchar('0'));
		else if (m->type == 'x')
			return (ft_putstr("0x"));
		else if (m->type == 'X')
			return (ft_putstr("0X"));
	}
	return (0);
}

int				pf_int_init(t_module *m, __int128 val, int base, char *base_str)
{
	int		i;

	m->val_str = ft_i128toa((val < 0 ? val * -1 : val), base, base_str);
	m->val_len = ft_strlen(m->val_str);
	m->prec = m->prec > 0 ? m->prec - m->val_len : -1;
	m->width -= m->prec > 0 ? (m->prec + m->val_len) : m->val_len;
	i = m->width;
	if (m->flag.plus || m->flag.space || val < 0)
		i--;
	if (m->flag.diese)
	{
		if (m->type == 'o' || m->type == 'O')
			i--;
		else if (m->type == 'x' || m->type == 'X')
			i -= 2;
	}
	return (i);
}

int				pf_int_moins(t_module *m, __int128 val, int i, int prec)
{
	int		total;

	total = 0;
	if (m->flag.plus || val < 0)
		total += val >= 0 ? ft_putchar('+') : ft_putchar('-');
	else if ((m->flag.space || m->flag.diese) && val >= 0)
		total += m->flag.space ? ft_putchar(' ') : pf_int_diese(m, val);
	while (prec-- > 0)
		total += ft_putchar('0');
	total += ft_putstr(m->val_str);
	while (i-- > 0)
		total += ft_putchar(' ');
	return (total);
}

int				pf_int_nmoins(t_module *m, __int128 val, int i, int prec)
{
	int		total;

	total = 0;
	if ((m->flag.plus || val < 0) && m->flag.zero)
		total += val >= 0 ? ft_putchar('+') : ft_putchar('-');
	else if ((m->flag.space || m->flag.diese) && val >= 0 && m->flag.zero)
		total += m->flag.space ? ft_putchar(' ') : pf_int_diese(m, val);
	while (i-- > 0)
	{
		if (m->flag.zero && m->prec < 0)
			total += ft_putchar('0');
		else
			total += ft_putchar(' ');
	}
	if ((m->flag.plus || val < 0) && !m->flag.zero)
		total += val >= 0 ? ft_putchar('+') : ft_putchar('-');
	else if ((m->flag.space || m->flag.diese) && val >= 0 && !m->flag.zero)
		total += m->flag.space ? ft_putchar(' ') : pf_int_diese(m, val);
	while (prec-- > 0)
	{
		total += ft_putchar('0');
	}
	total += ft_putstr(m->val_str);
	return (total);
}

int				pf_int(t_module *m, va_list args)
{
	__int128	val;
	int			i;

	val = (__int128)va_arg(args, int);
	i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, m->prec));
	else
		return (pf_int_nmoins(m, val, i, m->prec));
}
