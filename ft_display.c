/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:49:45 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 15:25:51 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

int	ft_display(const char *str, t_module *module, va_list *args)
{
	int	i;
	int	j;
	int	rab;

	i = 0;
	rab = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			rab += ft_valid_type(module, args);
			while (module->type && str[i] != module->type)
			{
				i++;
			}
		}
		else
			ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	return (i + rab);
}
