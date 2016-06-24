/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_w_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:46:48 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/24 15:08:38 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>

static int	pf_winchart_11(unsigned int val, unsigned char p,
							unsigned int mask, int fd)
{
	unsigned char	p1;
	unsigned char	p2;
	int				i;

	p2 = (val << 26) >> 26;
	p1 = ((val >> 6) << 27) >> 27;
	p = (mask >> 8) | p1;
	i = write(fd, &p, 1);
	p = ((mask << 24) >> 24) | p2;
	i += write(fd, &p, 1);
	return (i);
}

static int	pf_winchart_16(unsigned int val, unsigned char p,
							unsigned int mask, int fd)
{
	unsigned char	p3;
	unsigned char	p2;
	unsigned char	p1;
	int				i;

	p3 = (val << 26) >> 26;
	p2 = ((val >> 6) << 26) >> 26;
	p1 = ((val >> 12) << 28) >> 28;
	p = (mask >> 16) | p1;
	i = write(fd, &p, 1);
	p = ((mask << 16) >> 24) | p2;
	i += write(fd, &p, 1);
	p = ((mask << 24) >> 24) | p3;
	i += write(fd, &p, 1);
	return (i);
}

static int	pf_winchart_o(unsigned int val, unsigned char p,
							unsigned int mask, int fd)
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
	i = write(fd, &p, 1);
	p = ((mask << 8) >> 24) | p2;
	i += write(fd, &p, 1);
	p = ((mask << 16) >> 24) | p3;
	i += write(fd, &p, 1);
	p = ((mask << 24) >> 24) | p4;
	i += write(fd, &p, 1);
	return (i);
}

static int	pf_help(int size, unsigned int val, unsigned char p, int fd)
{
	if (size <= 7)
		return ((int)write(fd, &val, 1));
	else if (size <= 11)
		return (pf_winchart_11(val, p, 49280, fd));
	else if (size <= 16)
		return (pf_winchart_16(val, p, 14712960, fd));
	else
		return (pf_winchart_o(val, p, 4034953344, fd));
}

int			pf_winchart(t_module *m, va_list args, int f)
{
	wchar_t			*val;
	unsigned char	p;
	int				total;
	int				i;
	int				len;

	total = 0;
	i = m->prec;
	p = '\0';
	if (!(val = va_arg(args, wchar_t *)))
		return (write(f, "(null)", (m->prec < 0 || m->prec > 6) ? 6 : m->prec));
	len = ft_strlenwchar(val);
	val--;
	if (m->flag.moins)
		while (val++ && i-- && *val)
			total += pf_help(ft_binsize(*val), *val, p, f);
	i = m->width - (m->prec >= 0 && m->prec < len ? m->prec : len);
	while (i-- > 0)
		total += m->flag.zero && !m->flag.moins ?
			ft_putchar_fd('0', f) : ft_putchar_fd(' ', f);
	if (!m->flag.moins)
		while (val++ && m->prec-- && *val)
			total += pf_help(ft_binsize(*val), *val, p, f);
	return (total);
}
