/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:39:51 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/18 22:11:32 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_radix(t_list **a_head, t_list **b_head)
{
	int		*first_num;
	int		*sorted_num;

	first_num = make_numlist(a_head);
	*b_head = NULL;
	change_base(a_head);
	start_swap(a_head, b_head, 0);
	make_b_empty(a_head, b_head, 0);
	sorted_num = make_numlist(a_head);
	make_magic_list(a_head, first_num, sorted_num);
	change_base(a_head);
	start_swap(a_head, b_head, 1);
	make_b_empty(a_head, b_head, 1);
	exit(1);
}

void	start_swap(t_list **a_head, t_list **b_head, int flag)
{
	int		loop_size;
	int		swap_way;
	int		len;

	swap_way = 1;
	loop_size = ft_lstsize(a_head);
	len = loop_size;
	if (loop_size < 6)
		return (small_case(a_head, b_head, loop_size));
	if (loop_size > 80 && loop_size < 108)
		loop_size /= 3;
	while (loop_size > 0)
	{
		if (swap_way == 1)
			push_b(a_head, b_head, len, flag);
		else
			push_a(a_head, b_head, len, flag);
		swap_way *= -1;
		loop_size /= 3;
	}
}

void	push_b(t_list **a, t_list **b, int len, int flag)
{
	int		num;

	while (len > 0)
	{
		num = (*a)->base % 10;
		if (num < 2)
			(*a)->base /= 10;
		push_case_b(a, b, num, flag);
		len --;
	}
	while (*a != NULL)
	{
		num = (*a)->base % 10;
		(*a)->base /= 10;
		if (num == 2)
			push_case_b(a, b, 0, flag);
		else
			push_case_b(a, b, 1, flag);
	}
}

void	push_a(t_list **a, t_list **b, int len, int flag)
{
	int		num;

	while (len > 0)
	{
		num = (*b)->base % 10;
		if (num < 2)
			(*b)->base /= 10;
		push_case_a(a, b, num, flag);
		len --;
	}
	while (*b != NULL)
	{
		num = (*b)->base % 10;
		(*b)->base /= 10;
		if (num == 2)
			push_case_a(a, b, 0, flag);
		else
			push_case_a(a, b, 1, flag);
	}
}
