/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:28:27 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:28:29 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mask_flags(t_flags *flags, t_flags mask)
{
	flags->width = flags->width && mask.width;
	flags->minus = flags->minus && mask.minus;
	flags->zero = flags->zero && mask.zero;
	flags->point = flags->point && mask.point;
	flags->hash = flags->hash && mask.hash;
	flags->space = flags->space && mask.space;
	flags->plus = flags->plus && mask.plus;
}
