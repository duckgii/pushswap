/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:31:18 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/18 22:11:18 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing_list(t_list **head)
{
	int		*content_array;
	t_list	*temp_list;
	int		num;

	temp_list = *head;
	content_array = make_array(head);
	while (temp_list != NULL)
	{
		num = (int)temp_list->content;
		temp_list->idx = find_idx(num, content_array, ft_lstsize(head)) + 1;
		temp_list = temp_list->next;
	}
	check_ascending(content_array, ft_lstsize(head));
	free(content_array);
}

void	check_ascending(int	*num_array, int len)
{
	int	idx;

	idx = 0;
	while (idx + 1 < len)
	{
		if (num_array[idx] > num_array[idx + 1])
			return ;
		idx ++;
	}
	exit(1);
}

int	find_idx(int target, int *num_array, int len)
{
	int		count;
	int		idx;

	idx = 0;
	count = 0;
	while (idx < len)
	{
		if (target > num_array[idx])
			count ++;
		idx ++;
	}
	return (count);
}

int	*make_array(t_list **head)
{
	int		*array;
	int		len;
	int		idx;
	t_list	*temp_list;

	idx = 0;
	temp_list = *head;
	len = ft_lstsize(head);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
		exit(1);
	while (idx < len)
	{
		array[idx] = (int)temp_list->content;
		temp_list = temp_list->next;
		idx ++;
	}
	return (array);
}
