/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:50:28 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:50:33 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_nbr(void)
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

int	handle_nbr(va_list args, t_flags flags)
{
	int	len;
	int	count;
	int	nb;

	count = 0;
	nb = va_arg(args, int);
	len = ft_len_nbr(nb, 10);
	mask_flags(&flags, mask_nbr());
	if (nb == 0 && flags.point)
		len = 0;
	if (!flags.minus)
		count += ft_print_width(flags, len, nb < 0, 0);
	count += ft_print_sign(flags, nb < 0);
	count += ft_print_zero(flags, len, nb < 0, 0);
	if (len)
		count += ft_put_nbr(nb);
	if (flags.minus)
		count += ft_print_width(flags, len, nb < 0, 0);
	return (count);
}
