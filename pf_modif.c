/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:35:58 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/19 18:09:35 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_check_next(char c, t_module *module)
{
	if (module->modif[0] == c)
	{
		module->modif[1] = c;
		module->modif[2] = '\0';
		return (2);
	}
	module->modif[1] = '\0';
	return (1);
}

static int	pf_other_modif(char *c, int i, t_module *m)
{
	while (c[i] == 'h' || c[i] == 'l' || c[i] == 'j' || c[i] == 'z')
	{
		if ((c[i] == 'l' && m->modif[0] == 'h') || ((c[i] == 'z')
				&& (m->modif[0] == 'l' || m->modif[0] == 'h')) || c[i] == 'j')
		{
			m->modif[0] = c[i];
			if (c[i] == 'l')
				i += pf_check_next(c[i + 1], m);
			else
			{
				m->modif[1] = '\0';
				i++;
			}
		}
		else
			i++;
	}
	return (i);
}

int			pf_check_modif(char *str, t_module *module)
{
	if (str[0] == 'h' || str[0] == 'l')
	{
		module->modif[0] = str[0];
		return (pf_other_modif(str, pf_check_next(str[1], module), module));
	}
	if (str[0] == 'j' || str[0] == 'z')
	{
		module->modif[0] = str[0];
		module->modif[1] = '\0';
		return (pf_other_modif(str, 1, module));
	}
	module->modif[0] = '\0';
	return (0);
}
