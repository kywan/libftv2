/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:40:55 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 16:25:53 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

static int		pf_int_diese(t_module *m, __int128 val, int fd)
{
	if (val != 0 || m->type == 'p')
	{
		if (m->type == 'x' || m->type == 'p')
			return (ft_putstr_fd("0x", fd));
		else if (m->type == 'X')
			return (ft_putstr_fd("0X", fd));
	}
	if (m->type == 'o' || m->type == 'O')
		return (ft_putchar_fd('0', fd));
	return (0);
}

int				pf_int_init(t_module *m, __int128 val, int base, char *base_str)
{
	int		i;

	m->val_str = ft_i128toa((val < 0 ? val * -1 : val), base, base_str);
	m->val_len = ft_strlen(m->val_str);
	if (m->prec > 0)
		m->flag.zero = 0;
	m->prec = m->prec > 0 ? m->prec - m->val_len : m->prec;
	m->width -= m->prec > 0 ? (m->prec + m->val_len) : m->val_len;
	if (val == 0 && m->prec == 0)
		m->width++;
	m->prec < 0 ? m->prec = -1 : 0;
	i = m->width;
	if (m->flag.plus || m->flag.space || val < 0)
		i--;
	if (m->flag.diese)
	{
		if ((m->type == 'o' || m->type == 'O') && val > 0)
			i >= 0 ? i-- : m->prec--;
		else if (((m->type == 'x' || m->type == 'X') && val > 0)
				|| (m->type == 'p'))
			i -= 2;
	}
	return (i);
}

int				pf_int_moins(t_module *m, __int128 val, int i, int f)
{
	int		tot;
	int		prec;

	tot = 0;
	prec = m->prec;
	if (m->flag.plus || val < 0)
		tot += val >= 0 ? ft_putchar_fd('+', f) : ft_putchar_fd('-', f);
	else if ((m->flag.space || m->flag.diese) && val >= 0)
		tot += m->flag.space ? ft_putchar_fd(' ', f) : pf_int_diese(m, val, f);
	while (prec-- > 0)
		tot += ft_putchar_fd('0', f);
	tot += m->prec == 0 && val == 0 ? 0 : ft_putstr_fd(m->val_str, f);
	while (i-- > 0)
		tot += ft_putchar_fd(' ', f);
	return (tot);
}

int				pf_int_nmoins(t_module *m, __int128 v, int i, int fd)
{
	int		tot;
	int		prec;

	tot = 0;
	prec = m->prec;
	if ((m->flag.plus || v < 0) && m->flag.zero)
		tot += v >= 0 ? ft_putchar_fd('+', fd) : ft_putchar_fd('-', fd);
	else if ((m->flag.space || m->flag.diese) && v >= 0 && m->flag.zero)
		tot += m->flag.space ? ft_putchar_fd(' ', fd) : pf_int_diese(m, v, fd);
	while (i-- > 0)
	{
		if (m->flag.zero && m->prec < 0)
			tot += ft_putchar_fd('0', fd);
		else
			tot += ft_putchar_fd(' ', fd);
	}
	if ((m->flag.plus || v < 0) && !m->flag.zero)
		tot += v >= 0 ? ft_putchar_fd('+', fd) : ft_putchar_fd('-', fd);
	else if ((m->flag.space || m->flag.diese) && v >= 0 && !m->flag.zero)
		tot += m->flag.space ? ft_putchar_fd(' ', fd) : pf_int_diese(m, v, fd);
	while (prec-- > 0)
		tot += ft_putchar_fd('0', fd);
	tot += m->prec == 0 && v == 0 ? 0 : ft_putstr_fd(m->val_str, fd);
	return (tot);
}

int				pf_int(t_module *m, va_list args, int fd)
{
	__int128	val;
	int			i;

	val = (__int128)va_arg(args, int);
	i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}
