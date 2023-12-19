/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:04:24 by souahidi          #+#    #+#             */
/*   Updated: 2023/11/14 07:51:12 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
