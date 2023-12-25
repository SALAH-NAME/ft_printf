/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:10:22 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:10:26 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler(const char *str, va_list args, int *len)
{
	int				i;
	int				n;
	t_flags			flags;
	t_ft_flags		ft_flag;
	t_ft_specifiers	ft_specifier;

	i = 0;
	n = 0;
	reset_flags(&flags);
	ft_flag = ft_get_flag_func(str[i]);
	while (ft_flag)
	{
		n = ft_flag(str + i, &flags);
		if (n < 0)
			return (-2);
		i += n;
		ft_flag = ft_get_flag_func(str[i]);
	}
	if (!str[i])
		return (-3);
	ft_specifier = ft_get_specifier_func(str[i]);
	if (ft_specifier)
	{
		(*len) += ft_specifier(args, flags);
		i++;
	}
	return (i);
}
