/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:54:33 by pgrassin          #+#    #+#             */
/*   Updated: 2016/05/31 11:32:33 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> //a  suprimer juste pour debug
#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>
#include <ft_error.h>
#include <stdlib.h>

/*static void		ft_debug(t_module *module)
{
	printf("__________________________\n\tFLAGS\n");
	printf("'-' = %d|'+' = %d|' ' = %d|'#' = %d|'0' = %d\n",module->flag.moins,module->flag.plus,module->flag.space,module->flag.diese,module->flag.zero);
	printf("\tTAILLE\n");
	printf("width = %d| prec = %d\n", module->width, module->prec);
	printf("\tMODIF|TYPE|VALUE\n");
	printf("modif = %s|type = %c| ", module->modif, module->type);
	if (module->type == 'i')
		printf("value = %d\n", (int)module->arg);
	else
		printf("value = %lld\n", (long long)module->arg);
}*/

static int		ft_gestion(const char *str, va_list args)
{
	char	*s;
	t_module	*start_module;
	t_module	*work_module;

	start_module = NULL;
	s = ft_strdup(str);
	while (*s && s)
	{
		if (ft_strchr(s, '%'))
		{
			s = ft_strchr(s, '%') + 1;
			work_module = ft_createelem(&start_module);
			s += ft_check_flag(s, work_module);
			s += ft_check_width(s, work_module);
			s += ft_check_prec(s, work_module);
			s += ft_check_modif(s, work_module);
			work_module->type = *s;
			/*if (ft_error(work_module) != no_error)
			{
				//il y q une error
			}*/
//				ft_debug(work_module); //a suprimer
		}
		else
			return (ft_display(str, start_module, args)/*pas plus de '%'*/);
		(*s)++;
	}
	return (ft_display(str, start_module, args));
}

int				ft_printf(const char *format, ...)
{
	int		total;
	va_list	args;


	total = 0;
	va_start(args, format);
	total = ft_gestion(format, args);
	va_end(args);
	return (total);
}
