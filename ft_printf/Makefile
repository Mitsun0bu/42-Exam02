# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 10:50:16 by llethuil          #+#    #+#              #
#    Updated: 2021/12/30 16:40:44 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ./libftprintf.a

OBJS = ${SRCS:.c=.o}

INCS = ft_printf.h

SRCS = 	ft_printf.c			\

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c ${INCS} ${LIBFT_AR}
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
