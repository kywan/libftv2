/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_w_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:46:48 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/24 15:07:53 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <wchar.h>
#include <unistd.h>

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

int			pf_wint(t_module *m, va_list args, int fd)
{
	int				val;
	int				size;
	unsigned char	p;
	int				total;
	int				i;

	total = 0;
	i = 0;
	p = '\0';
	val = (int)va_arg(args, wint_t);
	size = ft_binsize(val);
	if (m->flag.moins)
		total += pf_help(size, val, p, fd);
	i = m->width - 1;
	while (i > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			total += ft_putchar_fd('0', fd);
		else
			total += ft_putchar_fd(' ', fd);
		i--;
	}
	if (!m->flag.moins)
		total += pf_help(size, val, p, fd);
	return (total);
}
