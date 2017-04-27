#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvictor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 21:15:36 by cvictor           #+#    #+#              #
#    Updated: 2016/07/26 22:55:45 by anicusan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

SOURCES = ./main.c ./init.c ./ft_print.c ./squares.c

OBJECTS = 
$(NAME) : all
all:
	@gcc -Wall -Werror -Wextra $(SOURCES)  -o $(NAME)
clean:
	@rm -f $(OBJECTS)
fclean:clean
	@rm -f $(NAME)
re: fclean all
