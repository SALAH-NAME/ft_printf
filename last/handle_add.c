/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:01:30 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:01:42 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_add(void)
{
	t_flags	mask;

	mask.width = 1;
	mask.width_len = 1;
	mask.minus = 1;
	mask.zero = 1;
	mask.point = 1;
	mask.point_len = 1;
	mask.hash = 0;
	mask.space = 1;
	mask.plus = 1;
	return (mask);
}

static int	handle_nil(t_flags flags)
{
	int		count;
	t_flags	new;

	count = 0;
	reset_flags(&new);
	new.width = flags.width;
	new.width_len = flags.width_len;
	new.minus = flags.minus;
	if (!flags.minus)
		count += ft_print_width(new, 5, 0, 0);
	count += write(1, "(nil)", 5);
	if (flags.minus)
		count += ft_print_width(new, 5, 0, 0);
	return (count);
}

int	handle_add(va_list args, t_flags flags)
{
	int				len;
	int				count;
	unsigned long	nb;

	count = 0;
	nb = va_arg(args, unsigned long);
	if (!nb)
		return (handle_nil(flags));
	len = ft_len_unbr(nb, 16);
	mask_flags(&flags, mask_add());
	if (!flags.minus)
		count += ft_print_width(flags, len, 0, 'p');
	if (nb)
	{
		count += ft_print_sign(flags, 0);
		count += ft_print_prefix(1);
		count += ft_print_zero(flags, len, 0, 1);
	}
	count += ft_put_base((unsigned long)nb, "0123456789abcdef");
	if (flags.minus)
		count += ft_print_width(flags, len, 0, 'p');
	return (count);
}
