/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:54:33 by pgrassin          #+#    #+#             */
/*   Updated: 2016/09/13 18:00:36 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

static void		ft_free(t_module *mod)
{
	t_module	*save;

	while (mod)
	{
		save = mod->next;
		//free(mod.flag);
		free(mod);
		mod = save;
	}
}

static int		pf_gestion(const char *str, va_list args, int fd)
{
	char		*s;
	char		*save;
	t_module	*start_module;
	t_module	*work_module;

	start_module = NULL;
	s = ft_strdup(str);
	save = s;
	while (*s && s)
	{
		if (ft_strchr(s, '%'))
		{
			s = ft_strchr(s, '%') + 1;
			work_module = pf_createelem(&start_module);
			s += pf_check_flag(s, work_module);
			s += pf_check_width(s, work_module);
			s += pf_check_prec(s, work_module);
			s += pf_check_modif(s, work_module);
			s += pf_check_flag(s, work_module);
			work_module->type = *s;
		}
		else
		{
			//ft_free(work_module);
			return (pf_display(str, start_module, args, fd));
		}
		(*s)++;
	}
	ft_free(work_module);
	return (pf_display(str, start_module, args, fd));
}

int				ft_printf(const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, format);
	total = pf_gestion(format, args, 1);
	va_end(args);
	return (total);
}

int				ft_printf_fd(int fd, const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, format);
	total = pf_gestion(format, args, fd);
	va_end(args);
	return (total);
}
