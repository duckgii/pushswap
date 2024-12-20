/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:06:29 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 19:49:18 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (new == NULL)
		return ;
	last = *lst;
	if (*lst != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}
