/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handle_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:12:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:36 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

const t_flags g_mask_int    = { 1,1, 1, 1,1, 1,1, 0, 1, 1};
const t_flags g_mask_add    = { 1,1, 1, 1,1, 1,1, 0, 1, 1};
const t_flags g_mask_hex    = { 1,1, 1, 1,1, 1,1, 1, 0, 0};
const t_flags g_mask_wid    = { 1,1, 1, 0,0, 0,0, 0, 0, 0};

int handle_char(va_list args, t_flags flags)
{
    char    c;
    (void)flags;

    c = va_arg(args, int);
    ft_put_char(c);

    // if (!(flags.minus && flags.width))
    // {
    //     // PRINT WIDTH
    // }
    // if (flags.minus && flags.width)
    // {
    //     // PRINT WIDTH
    // }
    return (1);
}

int handle_str(va_list args, t_flags flags)
{
    char *str;
    (void)flags;

    str = va_arg(args, char *);
    ft_put_str(str);
    // if (!(flags.minus && flags.width))
    // {
    //     // PRINT WIDTH
    // }
    // if (flags.point)
    // {
    //     ft_put_nstr(str, flags.point_len);
    // }
    // else
    // {
    //     ft_put_str(str);
    // }
    // if (flags.minus && flags.width)
    // {
    //     // PRINT WIDTH
    // }
    return (1);
}

int handle_nil(t_flags flags)
{
    t_flags new;

    reset_flags(&new);
    new.width = flags.width;
    new.width_len = flags.width_len;
    new.minus = flags.minus;
    if (!flags.minus)
        ft_print_width(new, 5, 0, 0);
    write(1, "(nil)",5);
    if (!flags.minus)
        ft_print_width(new, 5, 0, 0);
    return (5);
}

int handle_add(va_list args, t_flags flags)
{
    unsigned long nb;
    int len;
    (void)flags;
    
    nb = va_arg(args, unsigned long);
    if (!nb)
        return (handle_nil(flags));
    len = ft_len_unbr(nb, 16);
    mask_flags(&flags, g_mask_add);
    if (!flags.minus)
        ft_print_width(flags, len, 0, 1);
    if (nb)
    {
        ft_print_sign(flags, 0);
        ft_print_prefix(1);
        ft_print_zero(flags, len);
    }
    ft_put_add(nb, 1);
    if (flags.minus)
        ft_print_width(flags, len, 0, 1);    
    return (1);
}

int handle_lhex(va_list args, t_flags flags)
{
    unsigned int nb;
    int len;
    (void)flags;

    nb = va_arg(args, unsigned int);    

    len = ft_len_unbr(nb, 16);

    mask_flags(&flags, g_mask_hex);
    if (nb == 0 && flags.point)
        len = 0;
    if (!flags.minus)
        ft_print_width(flags, len, 0, 0);
    ft_print_sign(flags, 0);
    ft_print_prefix(flags.hash);
    ft_print_zero(flags, len);
    if (len)
        ft_put_lhex(nb);

    if (flags.minus)
        ft_print_width(flags, len, 0, 0);    

    return (1);
}
int handle_uhex(va_list args, t_flags flags)
{
    unsigned int nb;
    int len;
    (void)flags;

    nb = va_arg(args, unsigned int);    

    len = ft_len_unbr(nb, 16);

    mask_flags(&flags, g_mask_hex);
    if (nb == 0 && flags.point)
        len = 0;
    if (!flags.minus)
        ft_print_width(flags, len, 0, 0);
    ft_print_sign(flags, 0);
    ft_print_prefix(flags.hash);
    ft_print_zero(flags, len);
    if (len)
        ft_put_uhex(nb);

    if (flags.minus)
        ft_print_width(flags, len, 0, 0);    

    return (1);
}

int handle_nbr(va_list args, t_flags flags)
{
    int nb;
    int len;
    (void)flags;

    
    nb = va_arg(args, int);
    len = ft_len_nbr(nb, 10);
    if (nb == 0 && flags.point)
        len = 0;
    mask_flags(&flags, g_mask_int);
    if (!flags.minus)
        ft_print_width(flags, len, nb < 0, 0);
    ft_print_sign(flags, nb < 0);
    ft_print_zero(flags, len);
    if (len)
        ft_put_nbr(nb);
    if (flags.minus)
        ft_print_width(flags, len, nb < 0, 0);
    return (1);
}

int handle_unbr(va_list args, t_flags flags)
{
    unsigned int nb;
    (void)flags;

    nb = va_arg(args, unsigned int);
    return (ft_put_unb(nb));

}

int handle_ptc(va_list args, t_flags flags)
{
    (void)flags;
    (void)args;

    return (write(1, "%", 1));
}
