/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:09:59 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/24 11:35:41 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_ftoa(float n, int prec)
{
	char	*a;
	char	*cintpart;
	int		intpart;
	float	descpart;
	int		i;

	intpart = (int)n;
	descpart = n - (float)intpart;
	cintpart = ft_itoa(intpart);
	a = (char *)malloc(sizeof(char) * prec);
	if (!a)
		return (cintpart);
	if (prec != 0)
		a[0] = '.';
	i = 1;
	while (prec > 0)
	{
		a[i] = (int)(descpart * 10) + '0';
		descpart = (descpart * 10) - (int)(descpart * 10);
		prec--;
		i++;
	}
	a[i] = '\0';
	return (ft_strjoin(cintpart, a));
}
