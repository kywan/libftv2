/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:19:46 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/09 20:55:03 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		sum;
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
