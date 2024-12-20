/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:44:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 14:40:23 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_error(void);

static int	len_use(const char *string)
{
	int		len;

	len = 0;
	while (*string >= '0' && *string <= '9')
	{
		len ++;
		string ++;
	}
	if (*string == '\0')
		return (len);
	if (*string < '0' || *string > '9')
		put_error();
	return (len);
}

static void	check_long(const char *str, int flag)
{
	int	length;

	length = len_use(str);
	if (length < 10)
		return ;
	else if (length > 10)
		put_error();
	if (flag == -1 && (ft_strncmp("2147483648", str, 10) < 0))
		put_error();
	else if (flag == 1 && (ft_strncmp("2147483647", str, 10) < 0))
		put_error();
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	num;

	flag = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
			str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str ++;
	}
	if (*str == 0)
		put_error();
	while (*str == '0')
		str ++;
	check_long(str, flag);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str ++;
	}
	return (flag * num);
}

void	put_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
