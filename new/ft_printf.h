/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:10:53 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:14:48 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_flags
{
	int			width;
	int			width_len;
	int			minus;
	int			zero;
	int			point;
	int			point_len;
	int			hash;
	int			space;
	int			plus;
}				t_flags;

typedef struct s_flags_handler
{
	char		c;
	int			(*ft_flag)(const char *str, t_flags *flags);
}				t_flags_table;

typedef struct s_specifiers_handler
{
	char		c;
	int			(*ft_specifier)(va_list args, t_flags flags);
}				t_specifiers_table;

typedef int		(*t_ft_flags)(const char *str, t_flags *flags);
typedef int		(*t_ft_specifiers)(va_list args, t_flags flags);

int				ft_printf(const char *str, ...);
int				ft_onset(char *set, char c);
int				ft_handler(const char *str, va_list args, int *len);
void			reset_flags(t_flags *flags);
void			mask_flags(t_flags *flags, t_flags mask);
int				ft_len_unbr(unsigned long nb, int base);
int				ft_len_nbr(long nb, int base);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
t_ft_flags		ft_get_flag_func(char c);
t_ft_specifiers	ft_get_specifier_func(char c);
void			ft_flag_func_initializer(t_flags_table *func_flags);
void			ft_specifier_func_initializer(t_specifiers_table *f_sp);
int				handle_width(const char *str, t_flags *flags);
int				handle_point(const char *str, t_flags *flags);
int				handle_minus(const char *str, t_flags *flags);
int				handle_space(const char *str, t_flags *flags);
int				handle_hash(const char *str, t_flags *flags);
int				handle_plus(const char *str, t_flags *flags);
int				handle_zero(const char *str, t_flags *flags);
int				handle_str(va_list args, t_flags flags);
int				handle_add(va_list args, t_flags flags);
int				handle_nbr(va_list args, t_flags flags);
int				handle_ptc(va_list args, t_flags flags);
int				handle_char(va_list args, t_flags flags);
int				handle_lhex(va_list args, t_flags flags);
int				handle_uhex(va_list args, t_flags flags);
int				handle_uint(va_list args, t_flags flags);
int				ft_put_str(const char *s);
int				ft_put_nbr(long nb);
int				ft_put_char(const char c);
int				ft_put_nstr(const char *s, int n);
int				ft_put_nchar(const char c, int n);
int				ft_put_add(unsigned long nb, int add);
int				ft_put_base(unsigned long nb, char *base);
int				ft_print_prefix(int hex);
int				ft_print_zero(t_flags flags, int sp_len, int isnegative,
					int isaddress);
int				ft_print_sign(t_flags flags, int negative);
int				ft_print_width(t_flags flags, int sp_len, int isnegative,
					int isaddress);

#endif
