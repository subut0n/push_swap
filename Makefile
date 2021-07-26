.PHONY: all clean fclean re
NAME	= push_swap.a

PATH_INCS 	= includes
PATH_SRCS 	= srcs
PATH_OBJS 	= objs
PATH_LIBFT	= libft
LIBFT		= $(addprefix libft/, libft.a)

SRCS		=	$(addprefix $(PATH_SRCS)/, push_swap.c)
OBJS		=	$(addprefix $(PATH_OBJS)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(PATH_INCS)/push_swap.h $(PATH_LIBFT)/libft.h

GCC			= gcc
COMP_INC	= -I$(PATH_LIBFT) -I$(PATH_INCS)
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror

all:	 $(PATH_OBJS) $(NAME)

$(NAME):	$(OBJS) $(INCS) $(LIBFT)
			$(CC) $(CFLAGS) srcs/*.c  $(LIBFT) -o push_swap

$(PATH_OBJS)/%.o : $(PATH_SRCS)/*/%.c $(INCS)
				$(GCC) $(CFLAGS) $(COMP_INC) -c $< -o $@

$(PATH_OBJS):
		mkdir -p $(PATH_OBJS)

$(LIBFT):
		$(MAKE) -C $(PATH_LIBFT)

clean:
		$(RM) $(PATH_OBJS)
		$(RM) push_swap
		$(MAKE) -C $(PATH_LIBFT) clean

fclean:	clean
		$(RM) $(NAME)
		$(RM) push_swap
		$(MAKE) -C $(PATH_LIBFT) fclean

re:		fclean all