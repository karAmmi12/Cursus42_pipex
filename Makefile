# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 11:13:20 by kammi             #+#    #+#              #
#    Updated: 2024/02/29 18:08:08 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

LIBFT			=	libft.a

DIR_SRCS		=	srcs

DIR_OBJS		=	.objs

SRCS_NAMES		=	main.c utils.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Ilibft/includes -Iincludes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra -MMD

MAKEFLAGS		=	--no-print-directory

all				:	${NAME}

-include: $(DEPS)

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[34;5mpipex\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re:	fclean all

stop:
	rm -f ${NAME}

.PHONY:	all clean fclean re bonus
