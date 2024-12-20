/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:08:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/31 16:28:46 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_case(t_list **a, t_list **b, int list_len)
{
	t_list	*temp_a;

	if (list_len > 3)
		go_b(a, b, list_len);
	else
	{
		less_three_a(a);
		exit(1);
	}
	temp_a = *a;
	if (ft_lstsize(a) > 1)
	{
		if (temp_a->idx > temp_a->next->idx)
		{
			sa(a);
			ft_printf("sa\n");
		}
	}
	all_push_b(a, b);
	exit(1);
}

void	go_b(t_list **a, t_list **b, int list_len)
{
	while (list_len > 0)
	{
		if ((*a)->idx <= 3)
		{
			ft_printf("pb\n");
			pb(a, b);
		}
		else
		{
			ft_printf("ra\n");
			ra(a);
		}
		list_len --;
	}
	if (list_len > 4)
	{
		if ((*a)->idx > (*a)->next->idx)
		{
			ft_printf("sa\n");
			sa(a);
		}
	}
	less_three_b(b);
}

void	all_push_b(t_list **a, t_list **b)
{
	while (*b != NULL)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
}

void	less_three_a(t_list **a)
{
	if (ft_lstsize(a) == 3)
	{
		if ((*a)->idx > (*a)->next->idx)
		{
			ft_printf("sa\n");
			sa(a);
		}
		if ((*a)->next->idx > (*a)->next->next->idx)
		{
			rra(a);
			ft_printf("rra\n");
		}
		if ((*a)->idx > (*a)->next->idx)
		{
			sa(a);
			ft_printf("sa\n");
		}
		return ;
	}
	if ((*a)->idx > (*a)->next->idx)
	{
		ft_printf("sa\n");
		sa(a);
	}
}

void	less_three_b(t_list **b)
{
	if (ft_lstsize(b) == 3)
	{
		if ((*b)->idx < (*b)->next->idx)
		{
			ft_printf("sb\n");
			sb(b);
		}
		if ((*b)->next->idx < (*b)->next->next->idx)
		{
			rrb(b);
			ft_printf("rrb\n");
		}
		if ((*b)->idx < (*b)->next->idx)
		{
			sb(b);
			ft_printf("sb\n");
		}
		return ;
	}
	if ((*b)->idx < (*b)->next->idx)
	{
		ft_printf("sb\n");
		sb(b);
	}
}
