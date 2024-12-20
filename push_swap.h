/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:30:40 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/31 15:50:13 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"

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
void	ft_free(char **string);
void	indexing_list(t_list **head);
int		*make_array(t_list **head);
int		find_idx(int target, int *num_array, int len);
void	start_radix(t_list **a_head, t_list **b_head);
void	change_base(t_list **a);
void	start_swap(t_list **a_head, t_list **b_head, int flag);
void	push_b(t_list **a, t_list **b, int len, int flag);
void	push_a(t_list **a, t_list **b, int len, int flag);
void	small_case(t_list **a, t_list **b, int list_len);
void	make_b_empty(t_list **a_head, t_list **b_head, int flag);
int		*make_numlist(t_list **a);
void	make_magic_list(t_list **a, int *first_num, int *sorted_num);
void	change_num(t_list **a, int *num_list);
void	display(t_list **a, t_list **b);
void	push_case_b(t_list **a, t_list **b, int num, int flag);
void	push_case_a(t_list **a, t_list **b, int num, int flag);
int		make_digit_three(int num, int max_digit);
void	all_push_b(t_list **a, t_list **b);
void	less_three_a(t_list **a);
void	less_three_b(t_list **b);
void	check_ascending(int	*num_array, int len);
void	go_b(t_list **a, t_list **b, int list_len);

#endif
