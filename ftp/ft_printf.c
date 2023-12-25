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

int ft_handler(const char *str, va_list args)
{
    int             i;
    int             n;
    t_flags         flags;
    t_ft_flags      ft_flags;
    t_ft_specifiers ft_specifier;

    i = 0;
    n = 0;
    reset_flags(&flags);
    ft_flags = ft_get_flag_func(str[i]);
    while (ft_flags)
    {
        n = ft_flags(str + i, &flags);

        // if (n < 0)
        //     return (print_flags(flags), 1);

        i += n;
        ft_flags = ft_get_flag_func(str[i]);
    }

    ft_specifier = ft_get_specifier_func(str[i]);
    if (ft_specifier)
    {
        ft_specifier(args, flags);
        i++;
    }

	ft_put_char('\n');
	ft_put_char('\n');
    print_flags(flags);
    return (i);
}

int	ft_printf(const char *str, ...)
{
	int i;
    int n;

	va_list	args;

	va_start(args, str);
    i = 0;
    n = 0;
    ////  "% 10d"
    while (str && str[i])
    {
        if (str[i] == '%')
        {
            // printf("\nBEFORE:\nn = %d\t|\ti = %d\n\n", n, i);
            if (!str[i + 1])
                return (-1);
            else if (ft_onset("cspdiuxX%-0.# +123456789", str[i + 1]))
                n = ft_handler(&str[i + 1], args);
            // if (n < 0)
            //     return (-1);
            i += n;
            // printf("\n\nAFTER:\nn = %d\t|\ti = %d\n\n", n, i);
        }
        else
            ft_put_char(str[i]);
        i++;
    }

	va_end(args);
	return (0);
}
