/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:13:00 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/19 19:16:20 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	ft_binsize(long long i)
{
	char	*s;
	int		j;

	s = ft_i128toa(i, 2, "01");
	j = ft_strlen(s);
	free(s);
	return (j);
}
