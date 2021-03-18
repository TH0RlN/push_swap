# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agianico <agianico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 18:56:22 by antmarti          #+#    #+#              #
#    Updated: 2021/03/18 14:13:06 by agianico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c get_next_line_utils.c checker.c utils.c ft_split.c ft_free.c check_opts.c \
			exec.c

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Werror -Wextra -Wall

NAME =	checker

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