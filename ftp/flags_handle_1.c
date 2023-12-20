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

    len = 0;
    if (!str)
        return (-1);
    flags->point = 1;
    if (*str != '0')
    {
        flags->point = ft_atoi(str);
        while (ft_isdigit(str[len]))
            len++;
    }
    c = ft_onset("cspdiuxX%", str[len]);
    if (!c && *str != '0')
        return (-2);
    return (len);
}


int handle_minus(const char *str, t_flags *flags)
{
    int n;
    int c;

    n = 0;
    if (!str)
        return (-1);
    flags->minus = 1;


}
