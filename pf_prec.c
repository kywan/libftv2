/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:53:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/24 16:00:05 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	pf_collect_prec(t_module *m, va_list args)
{
	if (m->prec <= -2)
		while (m->prec_star > 0)
		{
			m->prec = va_arg(args, int);
			m->prec_star--;
		}
	else
		while (m->prec_star > 0)
		{
			va_arg(args, int);
			m->prec_star--;
		}
}

int		pf_check_prec(char *str, t_module *module)
{
	int	i;
	int	prec;

	if (*str == '.' && (i = 1))
	{
		if (ft_isdigit(*(++str)))
		{
			i++;
			if ((prec = ft_atoi(str)) >= 0)
				module->prec = prec;
			while ((prec /= 10) > 0 && i++)
				str++;
			str++;
		}
		else if (*str == '*')
		{
			module->prec_star++;
			module->prec = -2;
			i++;
		}
		else
			module->prec = 0;
		return (i + pf_check_prec(str, module));
	}
	return (0);
}
