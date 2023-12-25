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

static int	ft_handle_core(t_flags *flags, const char *str, int *i)
{
	int			n;
	t_ft_flags	ft_flag;

	n = 0;
	ft_flag = ft_get_flag_func(str[*i]);
	while (ft_flag)
	{
		n = ft_flag(str + (*i), flags);
		if (n < 0)
			return (n);
		(*i) += n;
		ft_flag = ft_get_flag_func(str[*i]);
	}
	return (1);
}

int	ft_handler(const char *str, va_list args, int *len)
{
	int				i;
	t_flags			flags;
	t_ft_specifiers	ft_specifier;

	i = 0;
	reset_flags(&flags);
	if (ft_handle_core(&flags, str, &i) == -42)
		return (-42);
	if (!str[i])
		return (-1);
	ft_specifier = ft_get_specifier_func(str[i]);
	if (ft_specifier)
	{
		(*len) += ft_specifier(args, flags);
		i++;
	}
	return (i);
}
