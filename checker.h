/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:30:40 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/22 20:23:16 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

void	check_repet(int *num_arr, int len);
char	*make_str(int argc, char *argv[]);
void	check_argc(int argc, char *argv[]);
void	make_list(char **str, t_list **a);
void	swap(t_list **head);
void	push(t_list **head_from, t_list **head_to);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
int		list_size(t_list **head);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	execute(char *command, t_list **a, t_list **b);
void	execute_len_2(char *command, t_list **a, t_list **b);
int		check_a(t_list **a, t_list **b);
void	ft_free(char **string);
char	**get_command(void);
char	**make_list_to_array(t_list **str_list);
char	**get_command(void);

#endif
