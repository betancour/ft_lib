# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: betanco <betanco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/29 12:00:00 by betanco           #+#    #+#              #
#    Updated: 2026/07/29 12:00:00 by betanco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= run_tests

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

ROOT		= ..
LIBFT		= $(ROOT)/libft.a
INC			= -I$(ROOT)/include -I.

SRCS		= main.c \
			  test_ctype.c \
			  test_mem.c \
			  test_str.c \
			  test_part2.c \
			  test_fd.c \
			  test_bonus.c \
			  test_bench.c

OBJS		= $(SRCS:.c=.o)

.PHONY: all test clean fclean re libft

all: $(NAME)

libft:
	$(MAKE) -C $(ROOT) bonus

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(ROOT) -lft -o $(NAME)

%.o: %.c test.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

test: $(NAME)
	./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
