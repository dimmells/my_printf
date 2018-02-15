/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:08:24 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/15 15:17:07 by dmelnyk          ###   ########.fr       */
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
int				print_int(va_list list, char *sp);
int				print_percent(char*sp);
void			get_flag(t_specifier *ts, char *sp);
void			get_length(t_specifier *ts, char *sp);
void			get_precision(t_specifier *ts, char *sp, int number);
void			get_width(t_specifier *ts, char *sp, char *arg);
void			add_space_tostr(t_specifier ts, char **print);
void			add_zeroes(t_specifier ts, char **print);
void			add_sign(t_specifier ts, char **print);
void			add_space(t_specifier ts, char **print);
void			add_precision(t_specifier ts, char *itoa, char **print);
t_specifier		struct_init(void);
char			*strjoin_n_del(char *s1, char *s2, int del);
char			*get_specifier_info(t_specifier *ts, char *sp, int number);
char			*llitoa_base(long long int number, int base);

#endif
