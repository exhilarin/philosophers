NAME = philo
SRCS = philo.c initalize.c actions.c terminate.c monitor.c utils.c
OBJS_DIR = Objects
OBJS = $(OBJS_DIR)/philo.o $(OBJS_DIR)/initalize.o $(OBJS_DIR)/actions.o $(OBJS_DIR)/monitor.o $(OBJS_DIR)/terminate.o $(OBJS_DIR)/utils.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf Objects

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
