/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:42:16 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/18 22:11:59 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str1;
	char			*str2;
	char			*ret_str;
	int				count_ret;
	int				count;

	if (s1 == NULL || s2 == NULL)
		exit(1);
	count = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	ret_str = (char *)malloc(count + 2);
	if (ret_str == NULL)
		exit(1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	count = -1;
	count_ret = 0;
	while (str1[++ count])
		ret_str[count_ret ++] = str1[count];
	ret_str[count_ret ++] = ' ';
	count = -1;
	while (str2[++ count])
		ret_str[count_ret ++] = str2[count];
	ret_str[count_ret] = '\0';
	return (ret_str);
}
