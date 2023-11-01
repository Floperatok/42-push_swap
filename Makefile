
# Colors
_GREEN=$'\033[0;32m

# Compilation
NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g # get rid of the -g before pushing

# Files
SRCS	=	src/main.c \
			src/init.c \
			src/utils.c \
			src/list_utils.c \
			src/list_utils2.c \
			src/operations1.c \
			src/operations2.c \
			src/operations3.c \
			lib/ft_printf/ft_printf.c \
			lib/ft_printf/ft_printf2.c \
			./dev_functions.c # delete this one before pushing
OBJECTS	=	$(SRCS:.c=.o)


all:	$(NAME) success

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

success:
	@echo "${_GREEN}*-----------------------------------*"
	@echo "${_GREEN}|      COMPILATION SUCCESSFUL       |"
	@echo "${_GREEN}*-----------------------------------*"
