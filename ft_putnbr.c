/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:46:17 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/24 12:45:49 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(long long nbr)
{
	unsigned long long	i;

	if (nbr < 0)
	{
		ft_putchar('-');
		i = -(unsigned long long)nbr;
	}
	else
		i = (unsigned long long)nbr;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar((char)i + '0');
}
