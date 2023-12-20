/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:36 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"


int	ft_put_char(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str(const char *s)
{
	int	count;

	count = 0;
	while (s && s[count])
		count += ft_put_char(s[count]);
	if (count)
		return (count);
	return (ft_put_str("(null)"));
}


int ft_put_unb(unsigned long nb)
{
    int count;

    count = 0;
    if (nb > 9)
        count += ft_put_unb(nb / 10);
    count += ft_put_char( '0' + (nb % 10));
    return (count);
}

int ft_put_lhex(unsigned int nb)
{
    int     count;
    char    *base;

    count = 0;
    base = "0123456789abcdef";
    if (nb > 15)
        count += ft_put_lhex(nb / 16);
    count += ft_put_char(base[nb % 16]);
    return (count);
}

int ft_put_uhex(unsigned int nb)
{
    int     count;
    char    *base;

    count = 0;
    base = "0123456789ABCDEF";
    if (nb > 15)
        count += ft_put_uhex(nb / 16);
    count += ft_put_char(base[nb % 16]);
    return (count);
}

int ft_put_add(unsigned long nb, int add)
{
    int     count;
    char    *base;

    count = 0;
    if (!nb)
        return (ft_put_str("(nil)"));
    if (add)
        count += ft_put_str("0x");
    base = "0123456789abcdef";
    if (nb > 15)
        count += ft_put_add(nb / 16, 0);
    count += ft_put_char(base[nb % 16]);
    return (count);
}


int	ft_onset(char *set, char c)
{
	while (set && *set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

int ft_len_nbr(long nb, int base)
{
    int count;

    count = 1;
    if (nb < 0)
    {
        nb = -nb;
        count++;
    }
    while (nb /= base)
        count++;
    return (count);
}


int ft_len_unbr(unsigned long nb, int base)
{
    int count;

    count = 1;
    while (nb /= base)
        count++;
    return (count);
}

// int print_buf(char *buf, unsigned int nbuf)
// {
//     return (write(1, buf, nbuf));
// }

// unsigned int handle_buf(char *buf, char c, unsigned int ibuf)
// {
//     if (ibuf == BUFFER_SIZE)
//     {
//         print_buf(buf, ibuf);
//         ibuf = 0;
//     }
//     buf[ibuf] = c;
//     ibuf++;
//     return (ibuf);
// }

int ft_handler(const char *str, va_list args)
{
    t_flags flags;
    int i;

    i = 0;
    flags = {0, 0, 0, 0, 0, 0, 0};
    if (str && ft_onset("cspdiuxX%",str[i]))
        ft_specifier_handler();
    else if (str && ft_onset("-0.# +123456789",str[i]))
    {
        ft_flags_handler(str, &flags);
    }
    else

}

int ft_specifier_handler(const char *str, va_list args)
{
    

}

int ft_flags_first(const char *str, t_flags *flags, int c)
{
    int i;

    i = 0;
    if (c == '-')
    {
        flags->minus++;
        if ((str + 1) && str[i] > '0' && str[i] <= '9')
        flags->minus = ft_atoi(str + 1);
        i += ft_len_unbr(flags->minus, 10);
    }
    else if (c == '0')
    {
        flags->zero++;
        if ((str + 1) && str[i] > '0' && str[i] <= '9')
        flags->zero = ft_atoi(str + 1);
        i += ft_len_unbr(flags->zero, 10);
    }
    else if (c == '.')
    {
        flags->point++;
        if ((str + 1) && str[i] > '0' && str[i] <= '9')
        flags->point = ft_atoi(str + 1);
        i += ft_len_unbr(flags->point, 10);
    }
    else
        return (-1);
}

int ft_flags_handler(const char *str, t_flags *flags)
{
    int i;
    int c;

    i = 0;
    while (str)
    {
        c = ft_onset("-0.# +123456789",str[i++]);
        if (!c)
            break;

        else if (c == '#')
            flags->hash++;
        else if (c == ' ')
            flags->space++;
        else if (c == '+')
            flags->plus++;
        else if (c > '0' && c <= '9')
        {
            flags->width = ft_atoi(str + i - 1);
            i += ft_len_unbr(flags->width) - 1;
        }
    }
}
    

int	ft_printf(const char *str, ...)
{
	int i;

	va_list	args;

	va_start(args, str);
    i = 0;
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            if (!str[i + 1])
                return (-1);
            else
                ft_handler(str + 1, args)
        }
        else
            ft_put_char(str[i]);
        i++;
    }

	
	va_end(args);
	return (0);
}