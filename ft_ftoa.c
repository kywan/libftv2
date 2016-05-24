/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:09:59 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/20 17:18:57 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_itos(int x, char str[], int d)
{
	int	i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	ft_strrev(str);
	str[i] = '\0';
	return (i);
}

void	ft_ftoa(float n, char *res, int prec)
{
	int	intpart;
	int	floatpart;
	int	i;

	intpart = (int)n;
	floatpart = n - (float)intpart;
	i = ft_itos(intpart, res, 0);
	if (prec != 0)
	{
		res[i] = '.';
		floatpart = floatpart * ft_pow(10, prec);
		ft_itos((int)floatpart, res + i + 1, prec);
	}
}
