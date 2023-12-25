/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:33:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:35:20 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nbr(long nb, int base)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		nb = -nb;
	}
	nb /= base;
	while (nb)
	{
		count++;
		nb /= base;
	}
	return (count);
}
