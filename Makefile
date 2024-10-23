NAME = push_swap
NAME_BONUS = checker
SRCS = src/main.c \
	src/parsing.c \
	src/error_manager.c \
	src/sorting.c \
	src/onchain_actions.c \
	src/literal_actions_a.c \
	src/literal_actions_b.c \
	src/literal_actions_shared.c \
	src/lst_utils.c \
	src/sort_three_elements.c \
	src/int_utils.c \
	src/element_move.c \
	src/matchmaking.c \
	src/score.c \
	src/stack_utils.c \
	src/clear.c

SRCS_BONUS = src/bonus/main_bonus.c \
	src/literal_actions_a.c \
	src/literal_actions_b.c \
	src/literal_actions_shared.c \
	src/error_manager.c \
	src/parsing.c \
	src/onchain_actions.c \
	src/lst_utils.c \
	src/clear.c \
	src/bonus/instructions_init.c \
	src/bonus/instructions_exec.c \
	src/bonus/clear.c \
	src/bonus/lst_instructions_utils.c \
	src/bonus/exit.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes/ -g
LIBS = src/utils/libft src/utils/get_next_line
BUILT_LIBS = src/utils/libft/libft.a src/utils/get_next_line/get_next_line.a

all : $(NAME)

$(NAME) : $(BUILT_LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(BUILT_LIBS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	for dir in $(LIBS); do \
      		make fclean -C $$dir; \
      	done

re : fclean all

$(BUILT_LIBS) :
	for dir in $(LIBS); do \
  		make -C $$dir; \
  	done

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BUILT_LIBS) $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(BUILT_LIBS) -o $(NAME_BONUS)
