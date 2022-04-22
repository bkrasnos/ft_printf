# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 11:47:34 by bkrasnos          #+#    #+#              #
#    Updated: 2022/04/22 13:47:32 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= srcs/ft_printf.c \
			srcs/ft_putchar.c \
			srcs/ft_putstr.c \
			srcs/ft_output_char.c \
			srcs/ft_output_string.c \
			srcs/ft_output_number.c \
			srcs/ft_output_number_unsigned.c \
			srcs/ft_output_hexadicimal.c \
			srcs/ft_output_hexadicimal_capital.c \
			srcs/ft_output_pointer.c \

OBJS	= ${SRCS:.c=.o}


INCS	= .

LIB		= ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all:		libft ${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS} 

libft:
			make -C ./libft
			cp libft/libft.a .
			mv libft.a ${NAME}

norm:
			norminette
clean:
			${RM} ${OBJS}
			make -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			make -C ./libft fclean

bonus:		${OBJS}
			make -C ./libft bonus
			cp libft/libft.a .
			mv libft.a ${NAME}
			${LIB} ${NAME} ${OBJS} 

re:			fclean all

.PHONY:		all clean fclean re .c.o norm libft
