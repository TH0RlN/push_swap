# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:23:34 by rarias-p          #+#    #+#              #
#    Updated: 2021/03/25 14:26:07 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_free.c push_swap.c utils.c

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Werror -Wextra -Wall

NAME =	swap

RM = rm -f

$(NAME):
		gcc -c $(FLAGS) $(SRCS)
		gcc $(FLAGS) $(SRCS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re