/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:50:54 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:51:01 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_uint(void)
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

int	handle_uint(va_list args, t_flags flags)
{
	int				len;
	int				count;
	unsigned int	nb;

	count = 0;
	nb = va_arg(args, unsigned int);
	len = ft_len_unbr(nb, 10);
	mask_flags(&flags, mask_uint());
	if (nb == 0 && flags.point)
		len = 0;
	if (!flags.minus)
		count += ft_print_width(flags, len, 0, 0);
	count += ft_print_zero(flags, len, 0, 0);
	if (len)
		count += ft_put_base(nb, "0123456789");
	if (flags.minus)
		count += ft_print_width(flags, len, 0, 0);
	return (count);
}
