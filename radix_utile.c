/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:29:25 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/18 17:50:30 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_b_empty(t_list **a_head, t_list **b_head, int flag)
{
	while (*b_head != NULL)
	{
		rrb(b_head);
		pa(a_head, b_head);
		if (flag == 1)
			ft_printf("rrb\npa\n");
	}
}

void	change_base(t_list **a)
{
	t_list	*temp_a;
	int		digit;
	int		list_size;
	int		reverse_num;

	digit = 1;
	temp_a = *a;
	list_size = ft_lstsize(a);
	while (list_size > 0)
	{
		digit *= 3;
		list_size /= 3;
	}
	while (temp_a != NULL)
	{
		reverse_num = make_digit_three(temp_a->idx, ft_lstsize(a));
		while (reverse_num > 0)
		{
			temp_a->base = temp_a->base * 10 + reverse_num % 10;
			reverse_num /= 10;
		}
		temp_a->base /= 10;
		temp_a = temp_a->next;
	}
}

int	make_digit_three(int num, int size)
{
	int	digit;
	int	return_value;
	int	temp_num;

	digit = 1;
	return_value = 1;
	temp_num = num;
	while (temp_num > 0)
	{
		digit *= 3;
		return_value = return_value * 10 + temp_num % 3;
		temp_num /= 3;
	}
	digit /= 9;
	if (size > digit * 4 || size < digit * 3)
		return (return_value);
	return_value = 1;
	while (digit > 1)
	{
		digit /= 3;
		return_value = return_value * 10 + num % 3;
		num /= 3;
	}
	return_value = return_value * 10 + num % 4;
	return (return_value);
}

void	push_case_a(t_list **a, t_list **b, int num, int flag)
{
	if (num == 0)
		pa(a, b);
	else if (num == 1)
	{	
		pa(a, b);
		ra(a);
	}
	else
		rb(b);
	if (flag == 1)
	{
		if (num == 0)
			ft_printf("pa\n");
		else if (num == 1)
			ft_printf("pa\nra\n");
		else
			ft_printf("rb\n");
	}
}

void	push_case_b(t_list **a, t_list **b, int num, int flag)
{
	if (num == 0)
		pb(a, b);
	else if (num == 1)
	{
		pb(a, b);
		rb(b);
	}
	else
		ra(a);
	if (flag == 1)
	{
		if (num == 0)
			ft_printf("pb\n");
		else if (num == 1)
			ft_printf("pb\nrb\n");
		else
			ft_printf("ra\n");
	}
}
