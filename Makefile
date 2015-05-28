# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 14:23:06 by eboeuf            #+#    #+#              #
#    Updated: 2014/02/09 19:57:24 by eboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serveur client

SRCS = serveur.c client.c

OBJS = $(SRCS:.c=.o)

HEAD = .

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

serveur :
		make -C libft
		$(CC) -c $(FLAGS) serveur.c -I libft -iquote $(HEAD)
		$(CC) -L libft -lft serveur.o -o serveur

client :
		make -C libft
		$(CC) -c $(FLAGS) client.c -I libft -iquote $(HEAD)
		$(CC) -L libft -lft client.o -o client

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) serveur client
