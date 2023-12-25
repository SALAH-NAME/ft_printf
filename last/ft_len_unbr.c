/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:45:32 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:46:26 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_unbr(unsigned long nb, int base)
{
	int	count;

	count = 1;
	nb /= base;
	while (nb)
	{
		count++;
		nb /= base;
	}
	return (count);
}
