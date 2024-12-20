/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:23:20 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/25 20:59:55 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	print_list;
	int		return_len;
	int		check;

	return_len = 0;
	va_start(print_list, str);
	while (*str)
	{
		check = return_len;
		if (before_p((char *)str, &return_len) == 0)
			return (-1);
		str += return_len - check;
		check = return_len;
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				return (return_len);
			if (after_p((char *)str, print_list, &return_len) == 0)
				return (-1);
			str++;
		}
	}
	va_end(print_list);
	return (return_len);
}

int	before_p(char *str, int *return_len)
{
	while (*str != '%' && *str != '\0')
	{
		if (write(1, str, 1) == -1)
			return (0);
		(*return_len)++;
		str ++;
	}
	return (1);
}

int	after_p(char *str, va_list print_list, int *return_len)
{
	if (*str == 'd' || *str == 'i')
		return (print_itos(va_arg(print_list, int), return_len));
	else if (*str == 'x' || *str == 'X')
		return (print_xtos(va_arg(print_list, unsigned int), return_len, *str));
	else if (*str == 'u')
		return (print_utos(va_arg(print_list, unsigned int), return_len));
	else if (*str == 'p')
		return (print_ptos(va_arg(print_list, unsigned long long), return_len));
	else if (*str == 'c')
		return (print_c((char)va_arg(print_list, int), return_len));
	else if (*str == 's')
		return (print_s(va_arg(print_list, void *), return_len));
	else if (*str == '%')
	{
		if (write(1, "%", 1) == -1)
			return (0);
		(*return_len)++;
		return (1);
	}
	if (write(1, str, 1) == -1)
		return (0);
	(*return_len)++;
	return (1);
}
