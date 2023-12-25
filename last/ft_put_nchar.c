/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:25:54 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:25:55 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nchar(const char c, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}
