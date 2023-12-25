/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:17:04 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:17:22 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_char(void)
{
	t_flags	mask;

	mask.width = 1;
	mask.width_len = 1;
	mask.minus = 1;
	mask.zero = 0;
	mask.point = 0;
	mask.point_len = 0;
	mask.hash = 0;
	mask.space = 0;
	mask.plus = 0;
	return (mask);
}

int	handle_char(va_list args, t_flags flags)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(args, int);
	mask_flags(&flags, mask_char());
	if (!flags.minus)
		count += ft_print_width(flags, 1, 0, 0);
	count += ft_put_char(c);
	if (flags.minus)
		count += ft_print_width(flags, 1, 0, 0);
	return (count);
}
