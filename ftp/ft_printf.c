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
	while (set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

int	ft_handler(va_list args, char *str)
{
	int	i;

	i = 0;
//	while (str && str[i])
//	{
//		if (ft_onset("-0.# +", str[i]))
//		{
//		}
//	}
}

int	ft_printf(const char *str, ...)
{
	
	va_list	args;

	va_start(args, str);

	
	va_end(args);
	return (0);
}
