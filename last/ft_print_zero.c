/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:46:51 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:46:52 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zero(t_flags flags, int sp_len, int isnegative, int isaddress)
{
	int	zero_len;
	int	point_len;

	zero_len = (flags.width_len - sp_len);
	point_len = (flags.point_len - sp_len);
	if (isnegative)
		zero_len -= 1;
	if (isaddress || flags.hash)
		zero_len -= 2;
	if (flags.point && (point_len > 0))
		return (ft_put_nchar('0', point_len));
	if (flags.zero && (zero_len > 0) && !flags.minus && !flags.point)
		return (ft_put_nchar('0', zero_len));
	return (0);
}
