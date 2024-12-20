/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:21:56 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 19:41:50 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *ccontent)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		exit(1);
	new->next = NULL;
	new->base = 0;
	new->content = ccontent;
	new->idx = 0;
	return (new);
}
