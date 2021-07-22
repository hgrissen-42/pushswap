NAME = push_swap

NAMEB = checker

ALGO = 	src/algo/directions.c \
		src/algo/index.c \
		src/algo/markup.c \
		src/algo/solve.c \
		src/algo/solve_a.c \
		src/algo/solve_b.c

OPERATIONS = 	src/ops/push.c \
				src/ops/rotate.c \
				src/ops/swap.c 

UTILS = src/utils/create_stack.c \
		src/utils/error_check.c \
		src/utils/utils1.c \
		src/utils/utils2.c 

SRC =	main.c $(ALGO) $(OPERATIONS) $(UTILS)

SRCB = src/bonus/bonus.c \
		src/bonus/utility.c $(OPERATIONS) $(UTILS)


CC = gcc -Wall -Wextra -Werror -I inc

all : $(SRC) $(NAME) 

$(NAME) : $(SRC)
		@$(CC) $(SRC) -o $(NAME)

bonus : $(SRCB) $(NAMEB)

$(NAMEB) : $(SRCB)
		@$(CC) $(SRCB) -o $(NAMEB)

clean :
		@rm $(NAME)

bclean :
		@rm $(NAMEB)

fclean : clean bclean

re : clean all

bre : bclean bonus