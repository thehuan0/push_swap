NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Push_swap sources
SRCS = srcs/main.c srcs/ft_atoi.c srcs/utils.c srcs/utils2.c \
	   srcs/stack_init.c srcs/stack_utils.c srcs/index.c \
	   srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
	   srcs/sort_small.c srcs/sort_utils.c srcs/position.c \
	   srcs/cost.c srcs/cost_utils.c srcs/sort.c srcs/sort_big.c \
	   srcs/ft_strcmp.c

# Checker sources (with simple GNL split into two files)
CHECK_SRCS = check/checker.c check/checker_gnl.c check/checker_gnl2.c

# Common sources needed for both
COMMON_SRCS = srcs/ft_atoi.c srcs/utils.c srcs/utils2.c \
			  srcs/stack_init.c srcs/stack_utils.c srcs/index.c \
			  srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
			  srcs/sort_small.c srcs/sort_utils.c srcs/position.c \
			  srcs/cost.c srcs/cost_utils.c srcs/sort.c srcs/sort_big.c \
			  srcs/ft_strcmp.c

# Object files
OBJS = $(SRCS:.c=.o)
CHECK_OBJS = $(CHECK_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CHECK_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(COMMON_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECK_OBJS) $(COMMON_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re