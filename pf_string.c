/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/19 15:21:24 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>

int	pf_string(t_module *m, va_list args)
{
	int		i;
	int		len;
	char	*value;
	int		total;

	if (!(value = ft_strdup(va_arg(args, char*))))
		value = ft_strdup("(null)");
	len = ft_strlen(value);
	total = 0;
	if (m->flag.moins)
		total = m->prec >= 0 ? ft_putstrlen(value, m->prec) : ft_putstr(value);
	i = m->width - (m->prec >= 0 && m->prec < len ? m->prec : len);
	m->width = i;
	while (i > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			total += ft_putchar('0');
		else
			total += ft_putchar(' ');
		i--;
	}
	if (!m->flag.moins)
		total += m->prec >= 0 ? ft_putstrlen(value, m->prec) : ft_putstr(value);
	free(value);
	return (total);
}
