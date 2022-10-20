# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 13:18:14 by whamoumi          #+#    #+#              #
#    Updated: 2021/07/23 16:57:46 by whamoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRCS		=	pile_functions.c pile_functions1.c pile_functions2.c \
				pile_functions3.c pile_functions4.c pile_functions5.c \
				pile_functions6.c pile_functions7.c pile_functions8.c \
				pile_functions9.c pile_functions10.c pile_functions11.c \
				pile_functions12.c 

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				${CC} -o ${NAME} ${OBJS} ${CFLAGS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
