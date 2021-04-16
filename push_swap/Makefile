# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 14:23:34 by rarias-p          #+#    #+#              #
#    Updated: 2021/04/06 13:45:58 by antmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_free.c push_swap.c utils.c swapping.c get_next_line_utils.c three_numbers.c \
			five_numbers.c p_opt.c r_opt.c rr_opt.c s_opt.c hundred_numbers.c hundred_utils.c \
			hundred_utils2.c

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Werror -Wextra -Wall

NAME =	push_swap

RM = rm -f

$(NAME):
		gcc -c $(FLAGS) $(SRCS)
		gcc $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re