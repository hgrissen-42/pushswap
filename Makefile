NAME_1 = push_swap

NAME_2 = checker

COMMON =	common/create_stack.c \
		common/error_check.c \
		common/push.c \
		common/rotate.c \
		common/swap.c \
		common/utils1.c \
		common/utils2.c 

SRC1 =	pushswapsrc/pushswap.c \
		pushswapsrc/directions.c \
		pushswapsrc/index.c \
		pushswapsrc/markup.c \
		pushswapsrc/solve.c \
		pushswapsrc/solve_a.c \
		pushswapsrc/solve_b.c $(COMMON)

SRC2 = checkersrc/checker.c checkersrc/utils.c $(COMMON)

CC = gcc -Wall -Wextra -Werror -I includes

all : $(SRC1) $(NAME_1) 

$(NAME_1) : $(SRC1)
		@$(CC) $(SRC1) -o $(NAME_1)

bonus :  $(NAME_2)
		
$(NAME_2):
		@$(CC) $(SRC2) -o $(NAME_2)

fclean :
		@rm $(NAME_1)

fbclean :
		@rm $(NAME_2)

re : fclean all

bre : fbclean bonus