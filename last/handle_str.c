/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:28:14 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/26 11:54:43 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	mask_str(void)
{
	t_flags	mask;

	mask.width = 1;
	mask.width_len = 1;
	mask.minus = 1;
	mask.zero = 0;
	mask.point = 1;
	mask.point_len = 1;
	mask.hash = 0;
	mask.space = 0;
	mask.plus = 0;
	return (mask);
}

static void	handle_null(char **str, t_flags *flags, int *len)
{
	if (*str)
		*len = ft_strlen(*str);
	if ((!(*str)) && flags->point && (flags->point_len < 6))
		flags->point_len = 0;
	else if ((!(*str)))
	{
		*len = 6;
		(*str) = "(null)";
	}
}

int	handle_str(va_list args, t_flags flags)
{
	int		len;
	int		count;
	char	*str;

	len = 0;
	count = 0;
	str = va_arg(args, char *);
	mask_flags(&flags, mask_str());
	handle_null(&str, &flags, &len);
	if (flags.point && (flags.point_len < len))
		len = flags.point_len;
	if (flags.point)
		flags.width_len += flags.point_len - len;
	if (!flags.minus)
		count += ft_print_width(flags, len, 0, 0);
	count += ft_put_nstr(str, len);
	if (flags.minus)
		count += ft_print_width(flags, len, 0, 0);
	return (count);
}
