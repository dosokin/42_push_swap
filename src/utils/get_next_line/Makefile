LIB_NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
HEADERS = get_next_line.h
CC = cc
FLAGS = -Wall -Wextra -Werror
CFLAGS = -g -Wall -Werror -Wextra -I ../../../includes/

all : $(LIB_NAME) clean

$(LIB_NAME) : $(OBJS)
	$(AR) rcs $(LIB_NAME) $(OBJS)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(LIB_NAME)

re : fclean all