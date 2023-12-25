/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:36 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"


void reset_flags(t_flags *flags)
{
    flags->width = 0;
    flags->width_len = 0;
    flags->minus = 0;
    flags->zero = 0;
    flags->zero_len = 0;
    flags->point = 0;
    flags->point_len = 0;
    flags->hash = 0;
    flags->space = 0;
    flags->plus = 0;
}


/// TEST FUNCTIONS
void print_flags(t_flags flags)
{
    printf("width:     %d\n", flags.width);
    printf("width_len: %d\n", flags.width_len);
    printf("minus:     %d\n", flags.minus);
    printf("zero:      %d\n", flags.zero);
    printf("zero_len:  %d\n", flags.zero_len);
    printf("point:     %d\n", flags.point);
    printf("point_len: %d\n", flags.point_len);
    printf("hash:      %d\n", flags.hash);
    printf("space:     %d\n", flags.space);
    printf("plus:      %d\n", flags.plus);
}



// int ft_print_width(t_flags flags, int n)
// {
//     int i;
//     int len;

//     return (0);
// }


int	ft_put_nchar(const char c, int n)
{
    int i;
    
    i = 0;
    while (i++ < n)
        write(1, &c, 1);
    return (n);
}

void mask_flags(t_flags *flags, t_flags mask)
{
    flags->width        = flags->width      && mask.width     ;
    flags->minus        = flags->minus      && mask.minus     ;
    flags->zero         = flags->zero       && mask.zero      ;
    flags->point        = flags->point      && mask.point     ;
    flags->hash         = flags->hash       && mask.hash      ;
    flags->space        = flags->space      && mask.space     ;
    flags->plus         = flags->plus       && mask.plus      ;
}

int ft_print_width(t_flags flags, int sp_len, int extra, int isadd)
{
    int width;
    int sign;
    int point_len;
    int zero_len;

    sign        = (flags.plus || flags.space);
    point_len   = (flags.point_len - sp_len);
    zero_len    = (flags.zero_len - sp_len);
    width       = (flags.width_len);
    // if (flags.zero)
    //     width = flags.zero_len;
    width   -= sp_len;
    if (sign && (!extra))
        width -= sign;
    if (flags.point && (point_len > 0))
        width -= point_len;
    if (flags.hash || isadd)
        width -= 2;
    if (flags.zero && !(flags.point || flags.minus) && (zero_len > 0))
        width -= zero_len;
    
    return (ft_put_nchar(' ', width));
}

int ft_print_sign(t_flags flags, int negative)
{
    if (negative == -1)
        return (-1);
    if (negative)
        return (ft_put_char('-'));
    else if (flags.plus)
        return (ft_put_char('+'));
    else if (flags.space)
        return (ft_put_char(' '));
    else
        return (0);
}

int ft_print_zero(t_flags flags, int sp_len)
{
    int zero_len;
    int point_len;
    
    zero_len    = (flags.zero_len - sp_len);
    point_len   = (flags.point_len - sp_len);
    
    if (flags.point && (point_len > 0))
        return (ft_put_nchar('0', point_len));
    if (flags.zero && (zero_len > 0) && !flags.minus)
        return (ft_put_nchar('0', zero_len));
    return (0);
}

int ft_print_prefix(int hex)
{
    if (hex)
        return (ft_put_str("0x"));
    return (0);
}
