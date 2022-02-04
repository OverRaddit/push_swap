CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libdeque.a

SRCS = deque.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : $(OBJS)
	rm -f $(OBJS)

fclean : $(OBJS) $(NAME)
	rm -f $^

re : fclean
	make all

bonus : $(FULLOBJS)
	ar rc $(NAME) $^

.PHONY : all clean fclean re bonus
