
# Colors
_GREEN=$'\033[0;32m

# Compilation
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	push_swap

SRC_PATH	=	src/
OBJ_PATH	=	obj/

# Files
SRC		=	main.c \
		initialization.c \
		utils.c \
		utils2.c \
		ft_split.c \
		list_utils.c \
		operations1.c \
		operations2.c \
		operations3.c \
		sort_utils.c \
		sort.c \
		target.c \
		moves.c \
		ft_printf.c \
		ft_printf2.c \
		dev_functions.c

SRCS	=	$(addprefix $(SRC_PATH), $(SRC))
OBJ		=	$(SRC:.c=.o)
OBJS	=	$(addprefix $(OBJ_PATH), $(OBJ))
INCS	=	-I ./includes/


all:	$(OBJ_PATH) $(NAME) success

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re: fclean all

success:
	@echo "${_GREEN}+-----------------------------------+"
	@echo "${_GREEN}|      COMPILATION SUCCESSFUL       |"
	@echo "${_GREEN}+-----------------------------------+"
