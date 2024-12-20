/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:57:47 by yeoshin           #+#    #+#             */
/*   Updated: 2024/01/10 17:22:16 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct ss_list
{
	char			*content;
	int				fd_num;
	struct ss_list	*next;
	int				buf_size;
	int				str_len;
}	t_tlist;

char	*get_next_line(int fd);
char	*substr(t_tlist *node, int idx_n);
t_tlist	*find_fd(int fd, t_tlist **head);
void	*all_free(t_tlist **head);
char	*delete_node(t_tlist **head, int fd, char *ret);
int		get_read(t_tlist *node, int fd);
void	str_join(t_tlist *node, char *str2, int read_len);
int		find_n(char *str, int str_len);
t_tlist	*new_node(t_tlist **head, int fd);
int		manage_buf(t_tlist *node, char *str, int read_len);

#endif