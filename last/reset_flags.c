/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:45:01 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:45:09 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags *flags)
{
	flags->width = 0;
	flags->width_len = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->point_len = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}
