# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 20:07:39 by mamellal          #+#    #+#              #
#    Updated: 2022/05/31 16:10:04 by mamellal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  philo.c utils.c utils1.c utils2.c

NAME = philo

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -g #-fsanitize=thread
all : $(NAME)	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all