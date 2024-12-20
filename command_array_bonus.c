/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:19:17 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 20:23:03 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**get_command(void)
{
	char	*read;
	char	*temp;
	t_list	*read_list;

	temp = NULL;
	read_list = NULL;
	while (1)
	{
		read = get_next_line(0);
		if (read == NULL)
			break ;
		ft_lstadd_back(&read_list, ft_lstnew((void *)ft_strdup(read)));
		free(read);
	}
	if (read_list == NULL)
		return (NULL);
	return (make_list_to_array(&read_list));
}

char	**make_list_to_array(t_list **str_list)
{
	t_list	*temp;
	t_list	*pre;
	char	**store_read;
	int		idx;
	int		len;

	idx = 0;
	pre = NULL;
	len = ft_lstsize(str_list);
	store_read = (char **)malloc(sizeof(char *) * (len + 1));
	if (store_read == NULL)
		exit(1);
	temp = *str_list;
	while (idx < len)
	{
		pre = temp;
		store_read[idx ++] = (char *)temp->content;
		temp = temp->next;
		free(pre);
	}
	free(temp);
	store_read[idx] = NULL;
	return (store_read);
}
