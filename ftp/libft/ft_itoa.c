/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:08:47 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/13 11:39:04 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_push_char(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	str[index++] = c;
	str[index] = '\0';
}

static void	ft_convert_push(int nbr, char *str)
{
	long int	number;

	number = 1;
	if (nbr < 0)
	{
		ft_push_char(str, '-');
		number *= -1;
	}
	number *= nbr;
	if (number >= 10)
		ft_convert_push(number / 10, str);
	ft_push_char(str, '0' + (number % 10));
}

static int	ft_calc_len(int n)
{
	long int	nb;
	size_t		count;

	count = 1;
	nb = n;
	if (nb <= 0)
	{
		count++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_calc_len(n);
	str = (char *)malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_convert_push(n, str);
	return (str);
}
