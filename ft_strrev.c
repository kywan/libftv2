/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:04:30 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 21:12:09 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		ft_swap((int *)&str[i], (int *)&str[len]);
		i++;
		len--;
	}
	return (str);
}
