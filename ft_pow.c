/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:29:18 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/18 15:16:23 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, int y)
{
	float	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
	{
		if (y > 0)
			return (x * temp * temp);
		else
			return ((temp * temp) / x);
	}
}
