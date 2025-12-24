NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJDIR = bin
INCLUDES = -Iincludes

# Push_swap sources
SRCS = srcs/main.c srcs/ft_atoi.c srcs/utils.c srcs/utils2.c \
       srcs/stack_init.c srcs/stack_utils.c srcs/index.c \
       srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
       srcs/sort_small.c srcs/sort_utils.c srcs/position.c \
       srcs/cost.c srcs/cost_utils.c srcs/sort.c srcs/sort_big.c \
       srcs/ft_strcmp.c

# Checker sources
CHECK_SRCS = check/checker.c check/get_next_line.c check/get_next_line_utils.c

# Common sources
COMMON_SRCS = srcs/ft_atoi.c srcs/utils.c srcs/utils2.c \
              srcs/stack_init.c srcs/stack_utils.c srcs/index.c \
              srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
              srcs/sort_small.c srcs/sort_utils.c srcs/position.c \
              srcs/cost.c srcs/cost_utils.c srcs/sort.c srcs/sort_big.c \
              srcs/ft_strcmp.c

# Object files (mapped to bin/)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
CHECK_OBJS = $(CHECK_SRCS:%.c=$(OBJDIR)/%.o)
COMMON_OBJS = $(COMMON_SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(CHECK_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(COMMON_OBJS) -o $(BONUS_NAME)

# Compile rule with directory creation
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
