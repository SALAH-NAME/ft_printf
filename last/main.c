/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:23:36 by souahidi          #+#    #+#             */
/*   Updated: 2023/12/25 11:23:38 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <limits.h>

int	main(void)
{
	char		*str;
	int			n;

	printf("\n");
	fflush(stdout);
	long x = 0;
	str = "%#10x";
	n = ft_printf(str, x);
	fflush(stdout);
	printf("$\nn => %d\n", n);
	fflush(stdout);
	printf("$\n");
	printf("$\n");
	n = printf(str, x);
	fflush(stdout);
	printf("$\nn => %d\n", n);
	return (0);
}
