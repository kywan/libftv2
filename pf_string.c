/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:08:05 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/21 15:59:04 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdarg.h>
#include <libft.h>
#include <stdlib.h>

int	pf_string(t_module *m, va_list args, int f)
{
	int		i;
	int		len;
	char	*v;
	int		t;

	if (!(v = ft_strdup(va_arg(args, char *))))
		v = ft_strdup("(null)");
	len = ft_strlen(v);
	t = 0;
	if (m->flag.moins)
		t = m->prec >= 0 ? ft_putstrlen_fd(v, m->prec, f) : ft_putstr_fd(v, f);
	i = m->width - (m->prec >= 0 && m->prec < len ? m->prec : len);
	while (i > 0)
	{
		if (m->flag.zero && !m->flag.moins)
			t += ft_putchar_fd('0', f);
		else
			t += ft_putchar_fd(' ', f);
		i--;
	}
	if (!m->flag.moins)
		t += m->prec >= 0 ? ft_putstrlen_fd(v, m->prec, f) : ft_putstr_fd(v, f);
	free(v);
	return (t);
}
