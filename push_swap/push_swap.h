/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:49:24 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 17:29:10 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_swap
{
	int			**nums;
	int			*order;
	int			*pos;
	int			tot_elem;
	int			a_elem;
	int			b_elem;
	char		*inst;
}				t_swap;

int		compare			(t_swap *swap);
int		ft_atoi			(const char *str);
void	ft_exit			(t_swap *swap);
void	ft_free_int		(int **arr);
char	*ft_strdup		(const char *s1);
size_t	ft_strlen		(const char *s);
void	sort			(t_swap *swap);
void	swapping		(t_swap *swap);
void	three_numbers	(t_swap *swap);

#endif