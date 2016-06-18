/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:53:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/18 15:03:37 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int	pf_check_prec(char *str, t_module *module)
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
			if ((prec = ft_atoi(str)) >= 0)
				module->prec = prec;
			while ((prec /= 10) > 0)
				i++;
		}
		else
			module->prec = 0;
		return (i);
	}
	return (i);
}
