/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrassin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:52:35 by pgrassin          #+#    #+#             */
/*   Updated: 2016/06/16 18:28:19 by pgrassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
#include <stdint.h>
typedef struct			s_flag
{
	int					moins;
	int					plus;
	int					space;
	int					diese;
	int					zero;

}						t_flag;

typedef struct			s_module
{
	t_flag				flag;
	int					width;
	int					prec;
	char				*modif;
	char				type;
	char				*val_str;
	int					val_len;
	struct s_module		*next;
}						t_module;

int						ft_printf(const char *format, ...);

int						pf_check_flag(char *str, t_module *module);

int						pf_check_width(char *str, t_module *module);

int						pf_check_prec(char *str, t_module *module);

int						pf_check_modif(char *str, t_module *module);

int						pf_valid_flag(t_module *module);

int						pf_valid_type(t_module *module, va_list args);

int						pf_display_error(int error, t_module *module);

t_module				*pf_createelem(t_module **module);

int						pf_display(const char *, t_module *mod, va_list args);

int						pf_int(t_module *module, va_list args);

int						pf_long(t_module *module, va_list args);

int						pf_longlong(t_module *module, va_list args);

int						pf_short(t_module *module, va_list args);

int						pf_sizet(t_module *module, va_list args);

int						pf_uint(t_module *module, va_list args);

int						pf_ulong(t_module *module, va_list args);

int						pf_ulonglong(t_module *module, va_list args);

int						pf_ushort(t_module *module, va_list args);

int						pf_string(t_module *module, va_list args);

int						pf_char(t_module *module, va_list args);

int						pf_uchar(t_module *module, va_list args);

int						pf_schar(t_module *module, va_list args);

int						pf_wint(t_module *module, va_list args);

int						pf_winchart(t_module *module, va_list args);

int						pf_intmaxt(t_module *module, va_list args);

int						pf_uintmaxt(t_module *module, va_list args);

int						pf_int_init(t_module *module, __int128 val, int base, char *base_str);

int						pf_int_moins(t_module *module, __int128 val, int i, int prec);

int						pf_int_nmoins(t_module *module, __int128 val, int i, int prec);

#endif
