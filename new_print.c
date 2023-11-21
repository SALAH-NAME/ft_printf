#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


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

int	ft_print_base(long nb, const char *base, size_t len_base, char flag)
{
	int     count;
	long    n;

	n = nb;
	count = 0;
	if (flag == 'p')
	    count += ft_putstr_null("0x");
	if (flag == '-' && n < 0)
	{
	    count += ft_putchar('-');
	    n = -n;
	}
	if (n >= len_base)
		count += ft_print_base(n / len_base, base, len_base, 0);
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
		return ft_print_base(va_arg(ptr, int), "0123456789", 10, '-');
	else if (*str == 'p')
		return ft_print_base(va_arg(ptr, unsigned long), "0123456789abcdef", 16, 'p');
	else if (*str == 'u')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789", 10, 0);
	else if (*str == 'x')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789abcdef", 16, 0);
	else if (*str == 'X')
		return ft_print_base(va_arg(ptr, unsigned int), "0123456789ABCDEF", 16, 0);
	else if (*str == '%')
		return ft_putchar('%');
	else
		return (-1);

}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ptr;
	int     checker;

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


int main()
{
	int x = ft_printf("test int => %%%>", &x);

	printf("\nmy test = %d", x);
	printf("\n\n");

	x = printf("test int => %%%\n", &x);
	printf("\n   test = %d", x);
	
// 	printf("\n\n+++ %d", printf("%>"));
	

}

