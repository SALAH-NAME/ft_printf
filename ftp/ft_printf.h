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

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_null(const char *s);
int	ft_putchar(const char c);

typedef int (*handler_func) (va_list args);

int	va_char(va_list args);
int	va_str(va_list args);

#endif
