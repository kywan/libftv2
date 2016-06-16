/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_w_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:46:48 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 18:26:10 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>
#include <wchar.h>
int	pf_wint(t_module *m, va_list args)
{
	wint_t	val;
	int		i;

	val = (wint_t)va_arg(args, wint_t);
	i = pf_int_init(m, val, 10, "0123456789");
	if (m->flag.moins)
		return (pf_int_moins(m, val, i, m->prec));
	else
		return (pf_int_nmoins(m, val, i, m->prec));
}

int	pf_winchart(t_module *m, va_list args)
{
/*	wchar_t	*value;
	int		i;
	int		len;
	int		total;
	int		ter;

	value = ft_strdup(va_arg(args, wchar_t*));
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
*/
	t_module *j;

	j = m;
	j = NULL;
	args = 0;
	return(0);
}
