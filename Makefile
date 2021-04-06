# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:31:40 by rarias-p          #+#    #+#              #
#    Updated: 2021/04/06 14:46:45 by antmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SW=	push_swap/ft_free.c push_swap/push_swap.c push_swap/utils.c \
			push_swap/swapping.c push_swap/get_next_line_utils.c push_swap/s_opt.c \
			push_swap/five_numbers.c push_swap/three_numbers.c push_swap/p_opt.c \
			push_swap/r_opt.c push_swap/rr_opt.c push_swap/hundred_numbers.c \
			push_swap/chunk_opt.c push_swap/hundred_utils.c push_swap/hundred_utils2.c

SRCS_CH=	checker/get_next_line.c checker/get_next_line_utils.c \
			checker/checker.c checker/utils.c checker/ft_split.c \
			checker/ft_free.c checker/check_opts.c checker/exec.c \
			checker/p_opt.c checker/r_opt.c checker/rr_opt.c checker/compare.c \
			checker/s_opt.c

FLAGS =	-Werror -Wextra -Wall

RM = rm -f


OBJS_SW =	$(SRCS_SW:.c=.o)

OBJS_CH =	$(SRCS_CH:.c=.o)

OBJS=	ft_free.o push_swap.o utils.o \
		swapping.o get_next_line_utils.o \
		get_next_line.o get_next_line_utils.o \
		checker.o utils.o ft_split.o \
		ft_free.o check_opts.o exec.o \
		p_opt.o r_opt.o rr_opt.o compare.o s_opt.o \
		five_numbers.o three_numbers.o hundred_numbers.o \
		chunk_opt.o hundred_utils.o hundred_utils2.o

NAME_SW = push_swap/push_swap

NAME_CH = checker/checker

$(NAME_CH):
		gcc -c $(FLAGS) $(SRCS_CH)
		gcc $(FLAGS) $(SRCS_CH) -o $(NAME_CH)

$(NAME_SW):
		gcc -c $(FLAGS) $(SRCS_SW)
		gcc $(FLAGS) $(SRCS_SW) -o $(NAME_SW)

all: 	$(NAME_CH) $(NAME_SW)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME_CH) $(NAME_SW)

re: fclean all

.PHONY: all clean fclean re