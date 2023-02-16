CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
NAME = philo
SRCS = philosophers.c /
		utils/validation.c /
		utils/ft_atoi_ws.c

$(NAME):  all

all:  $(PHILO)

${NAME}: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)
fclean: clean
	$(RM) $(PHILO) 

re: fclean all

.PHONY: all clean fclean re