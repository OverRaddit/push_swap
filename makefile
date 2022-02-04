CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -Wall -g

NAME = push_swap
#B_NAME = bonus_so_long

SRCS_DIR = ./src
SRCS = src/push_swap.c src/main.c
#SRCS_BONUS = src/bonus_so_long.c
OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(SRCS_BONUS:.c=.o)

# 외부라이브러리 모음 =================================================
LIB_NAME = ft
LIB_DIR = ./include/libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

DEQ_NAME = deque
DEQ_DIR = ./include/deque
DEQ = $(addprefix $(DEQ_DIR)/, libdeque.a)
# 외부라이브러리 모음 ===================================================

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(MAKE) -C $(DEQ_DIR) all
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) \
					-L$(DEQ_DIR) -l$(DEQ_NAME) $^ -o $@

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(DEQ_DIR) -I$(LIB_DIR) -c $< -o $@

all : $(NAME)


clean :
	rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(DEQ_DIR) clean

fclean :
	rm -rf $(NAME) $(OBJS)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(DEQ_DIR) fclean

re : fclean all

#bonus : $(LIBFT_LIB) $(B_SERVER)

.PHONY : all clean fclean re bonus