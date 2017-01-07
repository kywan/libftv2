/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:00:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/08/17 17:01:39 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(const char *s, char c)
{
	int nb;

	nb = 0;
	while (*s && ++nb)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (nb);
		else
			s++;
		}
	return (nb);
}