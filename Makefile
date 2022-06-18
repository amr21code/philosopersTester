# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 10:35:41 by anruland          #+#    #+#              #
#    Updated: 2022/06/15 10:46:34 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philotester
CC		=	gcc
CFLAGS	=	-pthread -Wall -Wextra -Werror -ggdb3

SRC		=	main.c \
			get_next_line.c \
			get_next_line_utils.c \
			# destruct.c \
			# error.c \
			# init.c \
			# ft_atoi.c \
			# ft_itoa.c \
			# ft_bzero.c \
			# ft_strlen.c \
			# ft_printerror.c \
			# ph_helper1.c

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f ./*.o

fclean: clean
	rm -f ./$(NAME)

re:	fclean all
