/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:28:01 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:30:44 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_lhex(void)
{
	t_flags	mask;

	mask.width = 1;
	mask.width_len = 1;
	mask.minus = 1;
	mask.zero = 1;
	mask.point = 1;
	mask.point_len = 1;
	mask.hash = 1;
	mask.space = 0;
	mask.plus = 0;
	return (mask);
}

int	handle_lhex(va_list args, t_flags flags)
{
	int				len;
	int				count;
	unsigned int	nb;

	count = 0;
	nb = va_arg(args, unsigned int);
	len = ft_len_unbr(nb, 16);
	mask_flags(&flags, mask_lhex());
	if (nb == 0 && flags.point)
		len = 0;
	if (!flags.minus)
		count += ft_print_width(flags, len, nb, 'x');
	count += ft_print_prefix(flags.hash && nb);
	count += ft_print_zero(flags, len, 0, 0);
	if (len)
		count += ft_put_base((unsigned long)nb, "0123456789abcdef");
	if (flags.minus)
		count += ft_print_width(flags, len, nb, 'x');
	return (count);
}
