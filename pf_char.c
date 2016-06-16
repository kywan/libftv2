/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:53:03 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 13:54:52 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdarg.h>

int	pf_char(t_module *m, va_list args)
{
	int		i;
	char	val;
	int		total;

	val = (char)va_arg(args, int);
	total = 0;
	if (m->flag.moins)
		total += ft_putchar(val);
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
		total += ft_putchar(val);
	return (total);
}
