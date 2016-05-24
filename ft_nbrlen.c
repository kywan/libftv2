/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:11:28 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 11:14:27 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}