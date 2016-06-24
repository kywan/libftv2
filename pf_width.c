/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:33:03 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/24 15:56:31 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	pf_collect_width(t_module *m, va_list args)
{
	if (m->width <= -1)
		while (m->width_star > 0)
		{
			if ((m->width = va_arg(args, int)) < 0)
			{
				m->width *= -1;
				m->flag.moins = 1;
			}
			m->width_star--;
		}
	else
		while (m->width_star > 0)
		{
			va_arg(args, int);
			m->width_star--;
		}
}

int		pf_check_width(char *str, t_module *module)
{
	int	i;
	int	width;

	i = 0;
	while ((width = ft_atoi(str + i)) || str[i] == '*')
	{
		module->width = width;
		if (width > 0)
			i++;
		while ((width /= 10) > 0)
			i++;
		if (str[i] == '*')
		{
			module->width_star++;
			module->width = -1;
			i++;
		}
	}
	return (i);
}
