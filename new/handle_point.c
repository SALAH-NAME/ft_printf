/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:02:41 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:02:47 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_point(const char *str, t_flags *flags)
{
	int	c;
	int	len;

	len = 1;
	if (!str)
		return (-1);
	flags->point = 1;
	while (str[len] == '0')
		len++;
	flags->point_len = ft_atoi(&str[len]);
	while (ft_isdigit(str[len]))
		len++;
	c = ft_onset("cspdiuxX%", str[len]);
	if (c)
		return (len);
	return (-1);
}
