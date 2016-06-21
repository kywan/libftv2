/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:53:03 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 16:26:42 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

int	pf_char(t_module *m, va_list args, int fd)
{
	int		i;
	char	val;
	int		total;

	val = (char)va_arg(args, int);
	total = 0;
	if (m->flag.moins)
		total += ft_putchar_fd(val, fd);
	i = m->width - 1;
	while (i > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		i--;
		total++;
	}
	if (!m->flag.moins)
		total += ft_putchar_fd(val, fd);
	return (total);
}

int	pf_schar(t_module *m, va_list args, int fd)
{
	signed char	val;
	int			i;

	val = (signed char)va_arg(args, int);
	i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}

int	pf_uchar(t_module *m, va_list args, int fd)
{
	unsigned char	val;
	int				i;

	m->flag.space = 0;
	m->flag.plus = 0;
	val = (unsigned char)va_arg(args, int);
	if (m->type == 'O' || m->type == 'o')
		i = pf_int_init(m, val, 8, "01234567");
	else if (m->type == 'x')
		i = pf_int_init(m, val, 16, "0123456789abcdef");
	else if (m->type == 'X')
		i = pf_int_init(m, val, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, fd));
	else
		return (pf_int_nmoins(m, val, i, fd));
}
