CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = philo
SRCS = philosophers.c \
		utils/validation.c \
		utils/atoi_ws.c \
		utils/get_time.c \
		utils/print_act.c \
		operations/actions.c \
		operations/routine.c \
		operations/initial.c


all: $(NAME)

${NAME}: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -g

clean:
	$(RM) $(NAME)
fclean: clean
	$(RM) $(PHILO) 

re: fclean all

.PHONY: all clean fclean re