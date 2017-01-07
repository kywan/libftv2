/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:21:47 by pgrassin          #+#    #+#             */
/*   Updated: 2015/12/11 18:57:41 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	len = len - i;
	if (!(str = ft_strsub((char *)s, i, len)))
		return (NULL);
	str[len] = '\0';
	return (str);
}
