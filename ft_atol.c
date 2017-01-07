/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:19:46 by pgrassin          #+#    #+#             */
/*   Updated: 2016/09/13 15:45:02 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	sum;
	int		i;
	int		neg;

	sum = 0;
	i = 0;
	neg = 1;
	while ((*str) && (ft_isspace(*str)))
		str++;
	if (*str == '+')
		str++;
	else if ((*str == '-') && (*str++))
		neg = -1;
	while (ft_isdigit(str[i]))
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (neg * sum);
}
