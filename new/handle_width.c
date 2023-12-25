/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:53:00 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:53:06 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_width(const char *str, t_flags *flags)
{
	int	len;
	int	c;

	if (!str)
		return (-1);
	len = 0;
	flags->width = 1;
	flags->width_len = ft_atoi(str);
	while (ft_isdigit(str[len]))
		len++;
	c = ft_onset("cspdiuxX%.", str[len]);
	if (c)
		return (len);
	return (-1);
}
