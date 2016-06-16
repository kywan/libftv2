/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 13:58:01 by pgrassin         ###   ########.fr       */
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
	int		ter;

	value = ft_strdup(va_arg(args, char*));
	len = ft_strlen(value);
	total = 0;
	if (m->flag.moins)
		total = m->prec >= 0 ? ft_putstrlen(value, m->prec) : ft_putstr(value);
	ter = (m->prec >= 0 && m->prec < len ? m->prec : len);
	i = m->width - ter;
	m->width = i;
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
		total += m->prec >= 0 ? ft_putstrlen(value, m->prec) : ft_putstr(value);
	free(value);
	return (total);
}
