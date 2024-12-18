NAME := libft.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra -Iinclude -c
SRC_DIR := ./src/
OBJ_DIR := ./obj/
SRC_FILES := $(wildcard $(SRC_DIR)*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))
OBJS := $(OBJ_FILES)
RM := rm -f

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all obj clean fclean re
