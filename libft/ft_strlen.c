/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:25:54 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/13 23:19:01 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	size_t	len;
	char	*temp;

	len = 0;
	temp = (char *)string;
	while (*temp)
	{
		len ++;
		temp ++;
	}
	return (len);
}
