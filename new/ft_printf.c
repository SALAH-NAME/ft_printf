/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:50:37 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:00:06 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	i = 0;
	n = 0;
	count = 0;
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			else if (ft_onset("cspdiuxX%-0.# +123456789", str[i + 1]))
				n = ft_handler(&str[i + 1], args, &count);
			if (n < 0)
				count += ft_put_char(str[i]);
			else
				i += n;
		}
		else
			count += ft_put_char(str[i]);
		i++;
	}
	return (va_end(args), count);
}
