/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:15:52 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/15 17:10:15 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_check_flag(char **format, t_module *module)
{
	if (**format == '-' || **format == '+' || **format == ' '
			|| **format == '#' || **format == '0')
	{
		
		return (ft_check_flag());
	}
	return (format);
}
