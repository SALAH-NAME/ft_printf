/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/06 11:54:40 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr_null(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		while ("(null)"[count])
			ft_putchar("(null)"[count++]);
	else
	{
		while (str && str[count])
		{
			write(1, str + count, 1);
			count++;
		}
	}
	return (count);
}

static int	ft_pbase(long nb, const char *base, size_t len_base, char flag)
{
	int				count;
	long			n;
	unsigned long ln;

	n = nb;
	count = 0;
	if (flag == 'p')
	{
		if (n == 0)
			return (ft_putstr_null("(nil)"));
		count += ft_putstr_null("0x");
	}
	if (flag == '-' && n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	ln = (unsigned long)n;
	if (ln >= (unsigned long)len_base)
		count += ft_pbase(ln / len_base, base, len_base, 0);
	count += ft_putchar(base[ln % len_base]);
	return (count);
}

static int	ft_caller(const char *str, va_list ptr)
{
	if ((*str) == 's')
		return (ft_putstr_null(va_arg(ptr, char *)));
	else if (*str == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (*str == 'd' || *str == 'i')
		return (ft_pbase(va_arg(ptr, int), "0123456789", 10, '-'));
	else if (*str == 'p')
		return (ft_pbase(va_arg(ptr, unsigned long), "0123456789abcdef", 16,
				'p'));
	else if (*str == 'u')
		return (ft_pbase(va_arg(ptr, unsigned int), "0123456789", 10, 0));
	else if (*str == 'x')
		return (ft_pbase(va_arg(ptr, unsigned int), "0123456789abcdef", 16, 0));
	else if (*str == 'X')
		return (ft_pbase(va_arg(ptr, unsigned int), "0123456789ABCDEF", 16, 0));
	else if (*str == '%')
		return (ft_putchar('%'));
	else if (*str == '\0')
		return (-1);
	else
	{
		ft_putchar('%');
		ft_putchar(*str);
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ptr;
	int		checker;

	count = 0;
	va_start(ptr, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			checker = ft_caller(str, ptr);
			if (checker == -1)
				return (-1);
			count += checker;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(ptr);
	return (count);
}
