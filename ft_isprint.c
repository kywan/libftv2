/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:43:33 by pgrassin          #+#    #+#             */
/*   Updated: 2015/11/23 17:22:06 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
