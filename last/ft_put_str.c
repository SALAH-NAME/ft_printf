/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:36:17 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:36:18 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(const char *s)
{
	int	count;

	count = 0;
	while (s && s[count])
		count += ft_put_char(s[count]);
	return (count);
}
