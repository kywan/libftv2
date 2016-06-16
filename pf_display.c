/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:49:45 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 13:27:57 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

int	pf_display(const char *str, t_module *module, va_list args)
{
	int	i;
	int	j;
	int	rab;

	i = 0;
	rab = 0;
	j = 0;
	while (str[i +j])
	{
		if (str[i + j] == '%')
		{
			rab += pf_valid_type(module, args);
			j++;
			while (module->type && str[i + j] != module->type)
				j++;
			j++;
			module = module->next;
		}
		else
		{
			ft_putchar(str[i + j]);
			i++;
		}
	}
	return (i + rab);
}
