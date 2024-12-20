/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:11:40 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/05 23:40:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	int		len;
	t_list	*pre;
	t_list	*temp;

	len = list_size(head);
	if (len < 2)
		return ;
	pre = *head;
	temp = pre->next;
	pre->next = temp->next;
	temp->next = pre;
	*head = temp;
}

void	push(t_list **head_from, t_list **head_to)
{
	int		len;
	t_list	*from_temp;

	len = list_size(head_from);
	if (len < 1)
		return ;
	from_temp = *head_from;
	*head_from = from_temp->next;
	from_temp->next = *head_to;
	*head_to = from_temp;
}

void	rotate(t_list **head)
{
	int		len;
	t_list	*last;
	t_list	*first;

	len = list_size(head);
	if (len < 2)
		return ;
	last = *head;
	first = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*head = first->next;
	first->next = NULL;
}

void	reverse_rotate(t_list **head)
{
	int		len;
	t_list	*last;
	t_list	*pre;

	len = list_size(head);
	if (len < 2)
		return ;
	last = *head;
	while (last->next != NULL)
	{
		pre = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	pre->next = NULL;
}

int	list_size(t_list **head)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		size ++;
	}
	return (size);
}
