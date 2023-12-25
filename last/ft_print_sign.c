/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:27:37 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:30:11 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_sign(t_flags flags, int negative)
{
	if (negative)
		return (ft_put_char('-'));
	else if (flags.plus)
		return (ft_put_char('+'));
	else if (flags.space)
		return (ft_put_char(' '));
	else
		return (0);
}
