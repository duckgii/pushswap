/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:28 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/31 15:22:40 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_a(t_list **a, t_list **b)
{
	int		pre_num;
	t_list	*temp;

	if (a == NULL)
		return (0);
	if (ft_lstsize(a) < 2 && ft_lstsize(b) == 0)
		return (1);
	if (ft_lstsize(b) != 0)
		return (0);
	temp = (*a)->next;
	pre_num = (int)(*a)->content;
	while (temp != NULL)
	{
		if ((int)temp->content < pre_num)
			return (0);
		pre_num = (int)temp->content;
		temp = temp->next;
	}
	return (1);
}
