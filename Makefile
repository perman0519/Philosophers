#-------------------------------------------
GREEN		=	"\033[0;32m"
EOC			=   "\033[0;0m"
#-------------------------------------------
SRC_DIR	=	./philosopher_mutex
NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	main.c philo_init.c
SRC		:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJ		=	$(SRC:.c=.o)

all 	: $(NAME)
	@echo $(GREEN) "philosopher made." $(EOC)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)
	@echo $(GREEN)"cleaned." $(EOC)

fclean	: clean
	$(RM) $(NAME)
	@echo $(GREEN)"f cleaned." $(EOC)

re		: fclean all

debug	:
	$(CC) $(CFLAGS) -g $(SRC)

.PHONY	: clean fclean re