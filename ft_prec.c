/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:53:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/22 13:08:57 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	ft_check_prec(char *str, t_module *module)
{
	int	i;
	int	prec;

	i = 0;
	if (*str == '.')
	{
		i++;
		if (ft_isdigit(*(++str)))
		{
			i++;
			prec = ft_atoi(str);
			module->prec = prec;
			while ((prec /= 10) > 0)
				i++;
		}
		return (i);
	}
	return (i);
}
