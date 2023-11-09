####################################################################
#                            CONFIG                                #
####################################################################

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
NAME		=	push_swap
NAME_BONUS	=	checker


####################################################################
#                            FILES                                 #
####################################################################

MAIN		=	main.c

SRC			=	initialization.c utils.c utils2.c ft_split.c \
				list_utils.c push.c swap.c rotate.c \
				reverse_rotate.c sort_utils.c sort.c target.c \
				moves.c ft_printf.c ft_printf2.c dev_functions.c \
				push_swap.c

SRC_BONUS	=	checker.c get_next_line.c get_next_line_utils.c


####################################################################
#                            PATHS                                 #
####################################################################

OBJ_PATH	=	obj/
SRC_PATH	=	src/

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

SRCS_BONUS	=	$(addprefix $(SRC_PATH), $(SRC_BONUS))
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)
OBJS_BONUS	=	$(addprefix $(OBJ_PATH), $(OBJ_BONUS))

OBJ_MAIN	=	$(MAIN:.c=.o)
OBJS_MAIN	=	$(addprefix $(OBJ_PATH), $(OBJ_MAIN))

INCS		=	 ./include/


####################################################################
#                            RULES                                 #
####################################################################

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS) $(OBJS_MAIN)
	$(CC) $(CFLAGS) -I $(INCS) -o $@ $(OBJS) $(OBJS_MAIN)

$(NAME_BONUS):	$(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -I $(INCS) -o $@ $(OBJS) $(OBJS_BONUS)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(OBJ_PATH)%.o:	$(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)


re: fclean all
