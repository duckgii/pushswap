/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:30:02 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/31 15:17:34 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*all_str;
	char	**command;
	int		idx;

	idx = 0;
	a = NULL;
	b = NULL;
	all_str = make_str(argc, argv);
	make_list(ft_split(all_str, ' '), &a);
	command = get_command();
	while (command != NULL && command[idx] != NULL)
		execute(command[idx ++], &a, & b);
	if (check_a(&a, &b) == 1 && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(1);
	return (0);
}

char	*make_str(int argc, char *argv[])
{
	char	*all_str;
	char	*temp_str;
	int		idx;

	idx = 1;
	check_argc(argc, argv);
	all_str = argv[1];
	if (argc > 2)
	{
		while (idx < argc - 1)
		{
			if (*argv[idx] == '\0' || *argv[idx + 1] == '\0')
			{
				ft_printf("Error\n");
				exit(1);
			}
			temp_str = all_str;
			all_str = ft_strjoin(temp_str, argv[idx + 1]);
			if (idx > 1)
				free(temp_str);
			idx++;
		}
	}
	return (all_str);
}

void	check_argc(int argc, char *argv[])
{
	if (argc < 2)
		exit(1);
	else if (argc == 2 && *argv[0] == '\0')
	{
		ft_printf("Error\n");
		exit(1);
	}
}

void	make_list(char **str, t_list **a)
{
	int						idx;
	unsigned long long		num;
	int						*num_arr;
	t_list					*temp;

	idx = 0;
	while (str[idx] != NULL)
	{
		num = ft_atoi(str[idx]);
		ft_lstadd_back(a, ft_lstnew((void *)num));
		idx++;
	}
	idx = 0;
	num_arr = (int *)malloc(sizeof(int) * ft_lstsize(a));
	if (num_arr == NULL)
		exit(1);
	temp = *a;
	while (temp != NULL)
	{
		num_arr[idx++] = (int)temp->content;
		temp = temp->next;
	}
	check_repet(num_arr, ft_lstsize(a));
	ft_free(str);
}

void	check_repet(int *num_arr, int len)
{
	int		idx_a;
	int		idx_b;

	idx_a = 0;
	while (idx_a < len)
	{
		idx_b = idx_a + 1;
		while (idx_b < len)
		{
			if (num_arr[idx_a] == num_arr[idx_b])
			{
				ft_printf("Error\n");
				exit(1);
			}
			idx_b ++;
		}
		idx_a ++;
	}
	free(num_arr);
}
