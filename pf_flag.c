/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 11:16:31 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 13:28:49 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			pf_check_flag(char *str, t_module *module)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			module->flag.moins = 1;
		else if (str[i] == '+')
			module->flag.plus = 1;
		else if (str[i] == ' ')
			module->flag.space = 1;
		else if (str[i] == '#')
			module->flag.diese = 1;
		else if (str[i] == '0')
			module->flag.zero = 1;
		else
			return (i);
		i++;
	}
	return (i);
}
