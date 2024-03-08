# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 11:13:20 by kammi             #+#    #+#              #
#    Updated: 2024/03/08 18:04:12 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
LIBFT = libft/libft.a
MANDATORY_SRCS = $(wildcard srcs/mandatory/*.c)
BONUS_SRCS = $(wildcard srcs/bonus/*.c)
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MANDATORY_OBJS) -Llibft -lft -o $(NAME)

##bonus: $(LIBFT) $(BONUS_OBJS)
##	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) -Llibft -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) -Llibft -lft -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
