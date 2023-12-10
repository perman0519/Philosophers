#-------------------------------------------
GREEN		=	"\033[0;32m"
EOC			=   "\033[0;0m"
#-------------------------------------------
SRC_DIR	=	./philosopher_mutex
NAME	=	philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=thread
SRC		=	main.c philo_init.c philo_util.c philo_thread.c \
			get_time.c pass_time_thread.c eat_philo.c print_thread.c \
			monitor.c start_philo_thread.c lock_all_alive.c
SRC		:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJ		=	$(SRC:.c=.o)

all 	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo $(GREEN) "philosopher made." $(EOC)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)
	@echo $(GREEN) "cleaned." $(EOC)

fclean	: clean
	$(RM) $(NAME)
	@echo $(GREEN) "f cleaned." $(EOC)

re		: fclean all

debug	:
	$(CC) $(CFLAGS) -g $(SRC)

.PHONY	: clean fclean re
