# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 21:37:55 by fmoreira          #+#    #+#              #
#    Updated: 2022/08/03 10:45:52 by fmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	./src
SRC			=	ft_main.c \
				ft_set_protocol.c \
				ft_http_utils.c \
				ft_http.c \
				ft_ping_utils.c \
				ft_ping.c \
				ft_dns_utils.c \
				ft_dns.c

OBJ_DIR		=	./obj
OBJ			=	$(patsubst	%.c, $(OBJ_DIR)/%.o, $(SRC))

INCD_DIR	=	./include
INCD		=	monitoring.h

vpath	%.c	$(SRC_DIR)
vpath	%.h	$(INCD_DIR)

CC			=	gcc
NAME		=	monitoring
RM			=	rm -rf

LIBFT_DIR	=	./libs/libft/
LIBFT		=	./libs/libft/libft.a

all:	$(NAME)

$(NAME):		$(OBJ) $(LIBFT)
				$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):		
				@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o:	%.c	$(INCD_DIR)
				@mkdir -p $(OBJ_DIR)
				$(CC) -o $@ -I $(INCD_DIR) -c $<

clean:
				@$(RM) $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean

fclean:			clean
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean
				
re:				fclean all

.PHONY:	all clean fclean re