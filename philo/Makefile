SRC =		main.c \
			init_data.c \
			routine.c \
			end.c \
			monitoring.c \
			start_threads.c \
			utils.c \
			actions.c \
			prints.c \
			timing.c
			
NAME =		philo
FLAGS =		-Wall -Wextra -Werror

OBJ_DIR =	obj
OBJS =		$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -pthread -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	cc -g -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
