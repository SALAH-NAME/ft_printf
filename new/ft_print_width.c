/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:35:56 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:35:57 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(t_flags flags, int sp_len, int isnegative, int isaddress)
{
	int	width;
	int	sign;
	int	point_len;

	sign = (flags.plus || flags.space || (isnegative && !flags.hash));
	point_len = (flags.point_len - sp_len);
	width = (flags.width_len);
	width -= sp_len;
	if (sign)
		width -= sign;
	if (flags.point && (point_len > 0))
		width -= point_len;
	if ((flags.hash && isnegative) || isaddress)
		width -= 2;
	if (flags.zero && !flags.point)
		width = 0;
	return (ft_put_nchar(' ', width));
}
