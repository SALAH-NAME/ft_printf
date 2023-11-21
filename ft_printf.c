#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_null(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		count += ft_putstr_null("(null)");
	while (str && str[count])
	{
		write(1, str + count, 1);
		count++;
	}
	return (count);
}

int	ft_print_base(size_t nb, const char *base, size_t len_base)
{
	size_t	count;
	size_t	n;

	n = nb;
	count = 0;
	if (n >= len_base)
		count += ft_print_base(n / len_base, base, len_base);
	count += ft_putchar(base[n % len_base]);
	return (count);
}



int	ft_caller(const char *str, va_list ptr)
{
	if ((*str) == 's')
		return ft_putstr_null(va_arg(ptr, char *));
	else if (*str == 'c')
		return ft_putchar(va_arg(ptr, int));
	else if (*str == 'd' || *str == 'i')
		return ft_print_base(va_arg(ptr, int), "0123456789", 10);
	else if (*str == 'p')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789abcdef", 16);
	else if (*str == 'u')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789", 10);
	else if (*str == 'x')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789abcdef", 16);
	else if (*str == 'X')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789ABCDEF", 16);
	else if (*str == '%')
		return ft_putchar(va_arg(ptr, int));
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

	count = 0;
	va_start(ptr, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_caller(str, ptr);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(ptr);
	return (count);
}


int main()
{
	int x = ft_printf("test int => %p", &x);

	printf("\nmy test = %d", x);
	printf("\n\n");

	x = printf("test int => %p", &x);
	printf("\n   test = %d", x);
	printf("\n\n");
}
