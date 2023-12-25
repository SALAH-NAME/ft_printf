/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handle_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:36 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"


int handle_point(const char *str, t_flags *flags)
{
    int c;
    int len;

    len = 1;
    if (!str)
        return (-1);
    flags->point = 1;
    if (str[len] != '0')
    {
        flags->point_len = ft_atoi(&str[len]);
        while (ft_isdigit(str[len]))
            len++;
    }
    c = ft_onset("cspdiuxX%0", str[len]);
    if (!c)
        return (-2);
    return (len);
}


int handle_minus(const char *str, t_flags *flags)
{
    // int n;
    // int c;

    // n = 0;
    if (!str)
        return (-1);
    flags->minus = 1;
    return (1);
}

int handle_hash(const char *str, t_flags *flags)
{
    if (!str)
        return (-1);
    flags->hash = 2;
    return (1);
}

int handle_space(const char *str, t_flags *flags)
{
    if (!str)
        return (-1);
    flags->space = 1;
    return (1);
}

int handle_plus(const char *str, t_flags *flags)
{
    if (!str)
        return (-1);
    flags->plus = 1;
    return (1);
}

int handle_width(const char *str, t_flags *flags)
{
    int len;
    int c;

    len = 0;
    if (!str)
        return (-1);
    flags->width = 1;
    flags->width_len = ft_atoi(str);
    while (ft_isdigit(str[len]))
        len++;

    c = ft_onset("cspdiuxX%.", str[len]);
    if (!c || (flags->point && str[len] == '.'))
        return (-2);
    return (len);
}

int handle_zero(const char *str, t_flags *flags)
{
    int c;
    int len;

    len = 1;
    if (!str)
        return (-1);
    flags->zero = 1;
    flags->zero_len = ft_atoi(&str[len]);
    while (ft_isdigit(str[len]))
        len++;

    c = ft_onset("cspdiuxX%", str[len]);
    if (!c)
        return (-2);
    return (len);
}
