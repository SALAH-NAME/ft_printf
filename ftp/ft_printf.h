/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:10:53 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/17 10:56:01 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1024
// # endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>


typedef struct s_flags
{
    int width;
    int width_len;
    int minus;
    int zero;
    int zero_len;
    int point;
    int point_len;
    int hash;
    int space;
    int plus;
}   t_flags;

typedef struct s_flags_handler
{
    char c;
    int (*ft_flag)(const char *str, t_flags *flags);
}   t_flags_table;

typedef struct s_specifiers_handler
{
    char c;
    int (*ft_specifier)(va_list args, t_flags flags);
}   t_specifiers_table;


typedef int (*t_ft_flags)(const char *str, t_flags *flags);
typedef int (*t_ft_specifiers)(va_list args, t_flags flags);


// const t_flags g_mask_nbr  = { 1,1, 1, 1,1, 1,1, 0, 1, 1};

// const t_flags g_mask_hex  = { 1,1, 1, 1,1, 1,1, 1, 0, 0};

// const t_flags g_mask_uns  = { 1,1, 1, 1,1, 1,1, 0, 0, 0};

// const t_flags g_mask_add  = { 1,1, 1, 1,1, 1,1, 0, 1, 1};
// const t_flags g_mask_str  = { 1,1, 1, 0,0, 1,1, 0, 0, 0};
// const t_flags g_mask_char = { 1,1, 1, 0,0, 0,0, 0, 0, 0};


int	ft_printf(const char *str, ...);

int	ft_put_char(const char c);
int	ft_put_str(const char *s);
int	ft_put_nstr(const char *s, int n);
int ft_put_nbr(long nb);
int ft_put_unb(unsigned long nb);
int ft_put_lhex(unsigned int nb);
int ft_put_uhex(unsigned int nb);
int ft_put_add(unsigned long nb, int add);
int	ft_onset(char *set, char c);
int ft_len_nbr(long nb, int base);
int ft_len_unbr(unsigned long nb, int base);
int ft_handler(const char *str, va_list args);
int ft_specifier_handler(const char *str, va_list args);
t_ft_flags ft_get_flag_func(char c);
t_ft_specifiers ft_get_specifier_func(char c);

void ft_flag_func_initializer(t_flags_table *func_flags);
void ft_specifier_func_initializer(t_specifiers_table *func_specifiers);



void reset_flags(t_flags *flags);


int handle_point(const char *str, t_flags *flags);
int handle_minus(const char *str, t_flags *flags);
int handle_space(const char *str, t_flags *flags);
int handle_width(const char *str, t_flags *flags);
int handle_hash(const char *str, t_flags *flags);
int handle_plus(const char *str, t_flags *flags);
int handle_zero(const char *str, t_flags *flags);

int handle_char(va_list args, t_flags flags);
int handle_lhex(va_list args, t_flags flags);
int handle_uhex(va_list args, t_flags flags);
int handle_unbr(va_list args, t_flags flags);
int handle_str(va_list args, t_flags flags);
int handle_add(va_list args, t_flags flags);
int handle_nbr(va_list args, t_flags flags);
int handle_ptc(va_list args, t_flags flags);


int	ft_put_nchar(const char c, int n);
void mask_flags(t_flags *flags, t_flags mask);
int ft_print_width(t_flags flags, int sp_len, int extra, int isadd);
int ft_print_sign(t_flags flags, int negative);
int ft_print_zero(t_flags flags, int sp_len);
int ft_print_prefix(int hex);


/// TEST FUNCTIONS
void print_flags(t_flags flags);

#endif
