NAME := Libft
CC := gcc
CFLAGS := -Wall -Werror -Wextra -Iincludes -c
LFLAGS := -Wall -Werror -Wextra -o
SRC_DIR := ./srcs/
OBJ_DIR := ./obj/
SRC_FILES := ./srcs/*.c
OBJ_FILES := $(SRC_FILES:.c=.o)
SRCS := $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS := $(addprefix $(OBJ_DIR), $(OBJ_FILES))
HEADER := -Iincludes/
RM := rm -f

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all obj clean fclean re
