#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
#	include <string.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(const char c);
int	ft_putstr_null(const char *str);
int	ft_print_base(long nb, const char *base, size_t len_base, char flag);
int	ft_caller(const char *str, va_list ptr);
int	ft_printf(const char *str, ...);


#endif
