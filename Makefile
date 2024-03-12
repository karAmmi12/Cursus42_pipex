# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 11:13:20 by kammi             #+#    #+#              #
#    Updated: 2024/03/12 12:25:26 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME = pipex
BONUS_NAME = pipex_bonus
LIBFT = libft/libft.a
HEADER = includes/pipex.h
HEADER_BONUS = includes/pipex_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

################################################################################
## SOURCES

MANDATORY_SRCS = srcs/mandatory/pipex.c\
				srcs/mandatory/utils.c\
				srcs/mandatory/utils2.c\

BONUS_SRCS = srcs/bonus/pipex_bonus.c\
				srcs/bonus/utils_bonus.c\
				srcs/bonus/utils2_bonus.c\
				srcs/bonus/here_doc_bonus.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o_bonus)

INCLUDES = -Iincludes/

################################################################################
## RULES

all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MANDATORY_OBJS) -Llibft -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) -Llibft -lft -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o_bonus: %.c $(HEADER_BONUS)
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
