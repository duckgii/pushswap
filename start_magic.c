/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:56:44 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/18 22:11:44 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_numlist(t_list **a)
{
	t_list	*temp;
	int		list_len;
	int		*num_array;
	int		index;

	index = 0;
	list_len = ft_lstsize(a);
	temp = *a;
	num_array = (int *)malloc(sizeof(int) * list_len);
	if (num_array == NULL)
		exit(1);
	while (temp != NULL)
	{
		num_array[index++] = temp->idx;
		temp = temp->next;
	}
	return (num_array);
}

void	make_magic_list(t_list **a, int *first_num, int *sorted_num)
{
	int		idx_one;
	int		idx_two;
	int		*num;
	int		size;

	size = ft_lstsize(a);
	num = (int *)malloc(sizeof(int) * size);
	if (num == NULL)
		exit(1);
	idx_one = -1;
	while (++idx_one < size)
	{
		idx_two = -1;
		while (++idx_two < size)
		{
			if (first_num[idx_two] == idx_one + 1)
			{
				num[idx_two] = sorted_num[idx_one];
				break ;
			}
		}
	}
	change_num(a, num);
	free(num);
}

void	change_num(t_list **a, int *num_list)
{
	t_list	*temp;
	int		index;

	temp = *a;
	index = 0;
	while (temp != NULL)
	{
		temp->idx = num_list[index];
		temp = temp->next;
		index ++;
	}
}
