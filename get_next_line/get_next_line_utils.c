/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:58:10 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/10 17:13:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_join(t_tlist *node, char *str, int read_len)
{
	int	idx;

	idx = 0;
	while (idx < read_len)
	{
		node->content[idx + node->str_len] = str[idx];
		idx++;
	}
	node->str_len += read_len;
}

int	find_n(char *str, int strlen)
{
	int	idx ;

	idx = 0;
	while (idx < strlen)
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

t_tlist	*new_node(t_tlist **head, int fd)
{
	t_tlist	*new;
	t_tlist	*pre;

	if (fd < 0)
		return (NULL);
	new = (t_tlist *)malloc(sizeof(t_tlist));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
		*head = new;
	else
	{
		pre = *head;
		while (pre->next != NULL)
			pre = pre->next;
		pre->next = new;
	}
	new->fd_num = fd;
	new->str_len = 0;
	new->buf_size = BUFFER_SIZE;
	new->next = NULL;
	new->content = (char *)malloc(BUFFER_SIZE);
	if (new->content == NULL)
		return (NULL);
	return (new);
}

char	*delete_node(t_tlist **head, int fd, char *ret)
{
	t_tlist	*pre;
	t_tlist	*now;

	pre = *head;
	if ((*head)->fd_num == fd)
	{	
		*head = (*head)->next;
		if (pre->content != NULL)
			free(pre->content);
		free(pre);
		return (ret);
	}
	now = pre->next;
	while (now->fd_num != fd)
	{
		pre = now;
		now = now->next;
	}		
	if (now->content != NULL)
		free(now->content);
	pre->next = now->next;
	free(now);
	return (ret);
}

void	*all_free(t_tlist **head)
{
	t_tlist	*now;
	t_tlist	*pre;

	now = *head;
	while (now != NULL)
	{
		if (now->content != NULL)
			free(now->content);
		pre = now;
		now = now->next;
		free(pre);
	}
	*head = NULL;
	return (NULL);
}
