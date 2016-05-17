/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:31:02 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/16 14:27:31 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5048

typedef struct		s_line
{
	int				fd;
	char			buff[BUFF_SIZE];
}					t_line;

int					get_next_line(int const fd, char **line);
#endif
