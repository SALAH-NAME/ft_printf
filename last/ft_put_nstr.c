/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:27:49 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:27:51 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nstr(const char *s, int n)
{
	int	count;

	count = 0;
	while (s && s[count] && count < n)
		count += ft_put_char(s[count]);
	return (count);
}
