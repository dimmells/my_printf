/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:08:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 19:15:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_specifier
{
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			is_it_have_size;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			width;
	int			precision;
	int			length;
}				t_specifier;

int				ft_printf(const char *format, ...);
int				get_specifier_len(const char **format);
int				max(int a, int b);
int				print_arg(const char **format, va_list list);
int				print_str(va_list list, char *sp);
int				print_int(va_list list, char *sp, char type);
int				print_percent(char*sp);
int				print_hex(va_list list, char *sp, char type);
int				print_octal(va_list list, char *sp, char type);
int				print_ui(va_list list, char *sp, char type);
int				print_char(va_list list, char *sp);
int				print_wchar_t(va_list list, char *sp);
int				print_pointer(va_list list, char *sp);
int				ft_putwchar_t(unsigned int wc);
int				get_bin_size(unsigned int wc);
int				get_size_wchar_t(unsigned int wc);
int				ft_putwstr(wchar_t *wstr);
int				print_wstr(va_list list, char *sp);
int				ft_wstrlen(wchar_t *wstr);
void			get_flag(t_specifier *ts, char *sp);
void			get_length(t_specifier *ts, char *sp);
void			get_precision(t_specifier *ts, char *sp, int number);
void			get_width(t_specifier *ts, char *sp);
void			add_space_tostr(t_specifier ts, char **print);
void			add_zeroes(t_specifier ts, char **print);
void			add_sign(t_specifier ts, char **print);
void			add_space(t_specifier ts, char **print);
void			add_precision(t_specifier ts, char *itoa, char **print);
void			add_precision_int(t_specifier ts, char *itoa, char **print);
void			add_space_towstr(t_specifier ts, char **print, wchar_t *wstr);
t_specifier		struct_init(void);
char			*get_specifier_info(t_specifier *ts, char *sp, int number);
char			*itoa_base(uintmax_t number, int base);
char			*get_argument_int(va_list list, t_specifier *ts);
char			*get_argument_base(va_list list, t_specifier *ts, int base);
char			*ft_str_toupper(char *str);

#endif
