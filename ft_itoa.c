/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:24:42 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/09 15:28:15 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char			*a;
	int				i;
	unsigned int	nb;

	a = (char *)malloc(sizeof(char) * 12);
	i = 0;
	if (!a)
		return (NULL);
	if (n < 0)
		nb = (unsigned int)(-n);
	else
		nb = (unsigned int)n;
	while (i == 0 || nb)
	{
		a[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	if (n < 0)
		a[i++] = '-';
	a[i] = '\0';
	ft_strrev(a);
	return (a);
}

static int	ft_i128toa_len(__int128 n, int base)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n && (n /= base))
		len++;
	return (len);
}

char		*ft_i128toa(__int128 n, unsigned int base, char *map)
{
	char	*buf;
	int		i;
	int		len;

	if (base > ft_strlen(map))
		return (NULL);
	len = ft_i128toa_len(n, base);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	i = len;
	buf[i--] = '\0';
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		buf[0] = map[0];
	while (n)
	{
		buf[i--] = map[n % base];
		n /= (int)base;
	}
	return (buf);
}
