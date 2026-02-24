.PHONY: all clean fclean re bonus

NAME		= push_swap
NAME_BONUS	= checker

PATH_INCS	= includes
PATH_SRCS	= srcs
PATH_OBJS	= objs
PATH_LIBFT	= libft
LIBFT		= $(PATH_LIBFT)/libft.a

SRCS		= $(PATH_SRCS)/push_swap.c \
			  $(PATH_SRCS)/parse.c \
			  $(PATH_SRCS)/check_args.c \
			  $(PATH_SRCS)/deque.c \
			  $(PATH_SRCS)/deque_utils.c \
			  $(PATH_SRCS)/action_swap.c \
			  $(PATH_SRCS)/action_push.c \
			  $(PATH_SRCS)/action_rotate.c \
			  $(PATH_SRCS)/action_rev_rotate.c \
			  $(PATH_SRCS)/act_write.c \
			  $(PATH_SRCS)/obtain_pos.c \
			  $(PATH_SRCS)/verif.c \
			  $(PATH_SRCS)/resolve_small_group.c \
			  $(PATH_SRCS)/resolve_big_group.c

SRCS_BONUS	= $(PATH_SRCS)/checker.c \
			  $(PATH_SRCS)/parse.c \
			  $(PATH_SRCS)/check_args.c \
			  $(PATH_SRCS)/deque.c \
			  $(PATH_SRCS)/deque_utils.c \
			  $(PATH_SRCS)/action_swap.c \
			  $(PATH_SRCS)/action_push.c \
			  $(PATH_SRCS)/action_rotate.c \
			  $(PATH_SRCS)/action_rev_rotate.c \
			  $(PATH_SRCS)/act_write.c \
			  $(PATH_SRCS)/obtain_pos.c \
			  $(PATH_SRCS)/verif.c \
			  $(PATH_SRCS)/resolve_small_group.c \
			  $(PATH_SRCS)/resolve_big_group.c \
			  $(PATH_SRCS)/get_next_line.c

OBJS		= $(patsubst $(PATH_SRCS)/%.c,$(PATH_OBJS)/%.o,$(SRCS))
OBJS_BONUS	= $(patsubst $(PATH_SRCS)/%.c,$(PATH_OBJS)/%.o,$(SRCS_BONUS))
INCS		= $(PATH_INCS)/push_swap.h $(PATH_LIBFT)/libft.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
COMP_INC	= -I$(PATH_LIBFT) -I$(PATH_INCS)
RM			= rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(COMP_INC) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(COMP_INC) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.c $(INCS)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(COMP_INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

clean:
	$(RM) $(PATH_OBJS)
	$(MAKE) -C $(PATH_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) -C $(PATH_LIBFT) fclean

re: fclean all
