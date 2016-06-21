/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_w_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:46:48 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 11:25:08 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <wchar.h>
#include <unistd.h>

static int	pf_winchart_11(unsigned int val, unsigned char p, unsigned int mask)
{
	unsigned char	p1;
	unsigned char	p2;
	int				i;

	p2 = (val << 26) >> 26;
	p1 = ((val >> 6) << 27) >> 27;
	p = (mask >> 8) | p1;
	i = write (1, &p, 1);
	p = ((mask << 24) >> 24) | p2;
	i += write (1, &p, 1);
	return (i);
}

static int	pf_winchart_16(unsigned int val, unsigned char p, unsigned int mask)
{
	unsigned char	p3;
	unsigned char	p2;
	unsigned char	p1;
	int				i;

	p3 = (val << 26) >> 26;
	p2 = ((val >> 6) << 26) >> 26;
	p1 = ((val >> 12) << 28) >> 28;
	p = (mask >> 16) | p1;
	i = write(1, &p, 1);
	p = ((mask << 16) >> 24) | p2;
	i += write(1, &p, 1);
	p = ((mask << 24) >> 24) | p3;
	i += write(1, &p, 1);
	return (i);
}

static int	pf_winchart_o(unsigned int val, unsigned char p, unsigned int mask)
{
	unsigned char	p4;
	unsigned char	p3;
	unsigned char	p2;
	unsigned char	p1;
	int				i;

	p4 = (val << 26) >> 26;
	p3 = ((val >> 6) << 26) >> 26;
	p2 = ((val >> 12) << 26) >> 26;
	p1 = ((val >> 18) << 29) >> 29;
	p = (mask >> 24) | p1;
	i = write(1, &p, 1);
	p = ((mask << 8) >> 24) | p2;
	i += write(1, &p, 1);
	p = ((mask << 16) >> 24) | p3;
	i += write(1, &p, 1);
	p = ((mask << 24) >> 24) | p4;
	i += write(1, &p, 1);
	return (i);
}

static int	pf_help(int size, unsigned int val, unsigned char p)
{
		if (size <= 7)
			return ((int)write(1, &val, 1));
		else if (size <= 11)
			return (pf_winchart_11(val, p, 49280));
		else if (size <= 16)
			return (pf_winchart_16(val, p, 14712960));
		else
			return (pf_winchart_o(val, p, 4034953344));
}

int			pf_winchart(t_module *m, va_list args)
{
	wchar_t			*val;
	unsigned char	p;
	int				total;
	int				i;
	int				len;
	int				lenhelp;

	total = 0;
	i = m->prec;
	p = '\0';
	if (!(val = ft_strdupwchar(va_arg(args, wchar_t *))))
		val = ft_strdupwchar((wchar_t *)"(null)");
	len = ft_strlenwchar(val);
	lenhelp = len;
	val--;
	if (m->flag.moins)
		while (val++ && i-- && *val/*lenhelp--*/)
			total += pf_help(ft_binsize(*val), *val, p);
	i = m->width - (m->prec >= 0 && m->prec < len ? m->prec : len);
	while (i-- > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			total += ft_putchar('0');
		else
			total += ft_putchar(' ');
	}
	if (!m->flag.moins)
		while (val++ && i-- && *val/*lenhelp--*/)
			total += pf_help(ft_binsize(*val), *val, p);
	return (total);
}

int			pf_wint(t_module *m, va_list args)
{
	unsigned int	val;
	int				size;
	unsigned char	p;
	int				total;
	int				i;

	total = 0;
	i = 0;
	p = '\0';
	val = (unsigned int)va_arg(args, wint_t);
	size = ft_binsize(val);
	if (m->flag.moins)
		total += pf_help(size, val, p);
	i = m->width - 1;
	while (i > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
		total++;
	}
	if (!m->flag.moins)
		total += pf_help(size, val, p);
	return (total);
}
