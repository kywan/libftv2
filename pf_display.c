/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:49:45 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/18 16:43:25 by pgrassin         ###   ########.fr       */
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
	int	len;

	i = 0;
	rab = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i + j] && (i + j) <= len)
	{
		if (str[i + j] == '%')
		{
			rab += pf_valid_type(module, args);
			j++;
			while (module->type && str[i + j] != module->type)
				j++;
			j++;
			if (module->type == '\x00')
				return (i + rab);
			module = module->next;
		}
		else
			i += ft_putchar(str[i + j]);
	}
	return (i + rab);
}
