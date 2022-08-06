# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 13:24:31 by fmoreira          #+#    #+#              #
#    Updated: 2022/08/01 22:18:07 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		ft_tolower.c ft_toupper.c ft_memset.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_strncmp.c ft_calloc.c ft_atoi.c ft_strdup.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_substr.c \
		ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_strcmp.c ft_get_next_line.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

LIB1	= ar -rcs

LIB2	= ranlib

all:		${NAME}

.c.o:	
			${CC} ${CFLAGS} -fPIC -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} ${PROGRAM}

${NAME}:	${OBJS}
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)

re:			fclean all

norme:
			norminette ft_*.c

.PHONY:		all clean fclean re compile .c.o $(NAME)
