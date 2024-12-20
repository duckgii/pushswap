/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:33:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 17:22:04 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute(char *command, t_list **a, t_list **b)
{
	int	len;

	len = ft_strlen(command) - 1;
	if (len == 3)
	{
		if (ft_strncmp(command, "rra", 3) == 0)
			rra(a);
		else if (ft_strncmp(command, "rrb", 3) == 0)
			rrb(b);
		else if (ft_strncmp(command, "rrr", 3) == 0)
			rrr(a, b);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	else if (len == 2)
		execute_len_2(command, a, b);
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	execute_len_2(char *command, t_list **a, t_list **b)
{
	if (ft_strncmp(command, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(command, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(command, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(command, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(command, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(command, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(command, "rr", 2) == 0)
		rr(a, b);
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
}
