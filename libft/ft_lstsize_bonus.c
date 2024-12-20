/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:56:24 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 20:04:37 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list **lst)
{
	int		len;
	t_list	*temp;

	temp = *lst;
	len = 0;
	if (lst == NULL || temp == NULL)
		return (0);
	while (temp != NULL)
	{
		len ++;
		temp = (temp->next);
	}
	return (len);
}
