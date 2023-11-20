#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		write(1, str + count, 1);
		count++;
	}
	return (count);
}

int	ft_print_base(int nb, const char* base, size_t len_base)
{
	long	n;

	n = nb;
	
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	va_start(ptr, str);
	while (str && *str)
	{
		if (*str++ == '%')
		{
			if ((str) == 's')
			else if (str == 'c')
			else if (str == 'd')
			else if (str == 'i')
			else if (str == 'p')
			else if (str == 'x')
			else if (str == 'X')
			else if (str == '%')
			else

		}
	}
	
}

int	main(void)
{

	return (0);
}