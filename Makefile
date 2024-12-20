CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

GNL_DIR = ./get_next_line/
GNL_SRCS = get_next_line.c\
			get_next_line_utils.c
GNL = $(addprefix $(GNL_DIR),$(GNL_SRCS))
GNL_OBJS = $(GNL:.c=.o)

BONUS = checker
BONUS_SRCS = checker.c\
			command_bonus.c\
			push_bonus.c\
			reverse_bonus.c\
			rotate_bonus.c\
			swap_bonus.c\
			execute_bonus.c\
			check_sort_bonus.c\
			free_bonus.c\
			command_array_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = ./libft/
LIB = $(LIBFT_DIR)libft.a 

PRINTF_DIR = ./printf/
PRINT = $(PRINTF_DIR)libftprintf.a

INCLIDE = -I./libft -I./printf

SRCS = command.c\
		push_swap.c\
		push.c\
		reverse.c\
		rotate.c\
		swap.c\
		free.c\
		indexing.c\
		radix_sort.c\
		small_case.c\
		start_magic.c\
		radix_utile.c

OBJS = $(SRCS:.c=.o)



all : $(NAME)

bonus : $(BONUS)

clean : 
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

$(NAME) : $(LIB) $(PRINT) $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(LIB) $(PRINT) $(BONUS_OBJS) $(GNL_OBJS)
		$(CC) $(CFLAGS) -o $@ $^

$(LIB) :
	make -C $(LIBFT_DIR) bonus

$(PRINT) : 
	make -C $(PRINTF_DIR) all

$(OBJS) : %.o : %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_OBJS) : %.o : %.c  checker.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(GNL_OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -I./get_next_line -c $< -o $@

.PHONY : all clean fclean re bonus



