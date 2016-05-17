/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 11:16:31 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/22 13:07:40 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_error.h>

int			ft_valid_flag(t_module *module)
{
	if (module->flag.moins && module->flag.zero)
		return (ft_display_error(incompflag_zeromoins, module));
	if (module->flag.space && module->flag.plus)
		return (ft_display_error(incompflag_spaceplus, module));
	return (no_error);
}

int			ft_check_flag(char *str, t_module *module)
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
