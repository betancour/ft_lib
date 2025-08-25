# Project name and output library
NAME := libft.a

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iinclude -c
# -c flag must precede -o in GCC syntax, handled in the rule below

# Directories
SRC_DIR := ./src/
OBJ_DIR := ./obj/

# Source and object files
SRC_FILES := $(wildcard $(SRC_DIR)*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))
OBJS := $(OBJ_FILES)

# Remove command
RM := rm -f

# Default target
all: obj $(NAME)

# Create object directory if it doesn't exist
obj:
	@mkdir -p $(OBJ_DIR)

# Compile source files to object files with header dependency
$(OBJ_DIR)%.o: $(SRC_DIR)%.c include/libft.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ -Iinclude

# Create the library archive
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean object files and directory
clean:
	@$(RM) -r $(OBJ_DIR)

# Clean everything
fclean: clean
	@$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all obj clean fclean re
