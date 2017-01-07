/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:40:41 by pgrassin          #+#    #+#             */
/*   Updated: 2016/03/16 14:32:24 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_process(char **buf, char **line, char **tmp)
{
	char	*tmp2;
	char	*tmp3;

	if (*buf)
	{
		if ((tmp2 = ft_strchr(*buf, '\n')))
		{
			*tmp2 = '\0';
			*line = ft_strjoin(*tmp, *buf);
			*tmp2 = '\n';
			return (1);
		}
		tmp3 = ft_strjoin(*tmp, *buf);
		if (*tmp)
			free(*tmp);
		*tmp = tmp3;
	}
	return (0);
}

static int	ft_help(char *tmp, char **buf, char **line)
{
	if (!(*tmp))
	{
		ft_memdel((void**)(buf));
		*line = NULL;
		return (0);
	}
	ft_memdel((void**)(buf));
	*line = tmp;
	return (1);
}

static char	**ft_lst_chr(int const fd, t_list **list)
{
	t_list	*i;

	i = *list;
	while (i && i->content_size != (size_t)fd)
		i = i->next;
	if (i)
		return ((char **)(&(i->content)));
	i = ft_lstnew(NULL, 0);
	i->content_size = (size_t)fd;
	ft_lstadd(list, i);
	return ((char **)(&(i->content)));
}

int			get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	char			**buf;
	ssize_t			rd;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = ft_lst_chr(fd, &list);
	tmp = (char *)malloc(sizeof(char));
	tmp[0] = '\0';
	while (!(ft_process(buf, line, &tmp)))
	{
		*buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if (*buf)
		{
			if ((rd = read(fd, *buf, BUFF_SIZE)) == -1)
				return (-1);
			(*buf)[rd] = '\0';
			if (rd == 0)
				return (ft_help(tmp, buf, line));
		}
	}
	ft_strcleanc(buf, '\n');
	return (1);
}
