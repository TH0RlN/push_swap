/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:49:24 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/30 18:02:52 by antmarti         ###   ########.fr       */
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
	int			*pos;
	int			tot_elem;
	int			a_elem;
	int			b_elem;
	char		*inst;
	int			opts;
}				t_swap;

int		check_opts		(char *opt);
int		compare			(t_swap *swap);
void	five_numbers	(t_swap *swap);
int		ft_atoi			(const char *str);
void	ft_exit			(t_swap *swap);
void	ft_free_int		(int **arr);
char	*ft_strdup		(const char *s1);
char	*ft_strjoin		(char const *s1, char const *s2);
size_t	ft_strlen		(const char *s);
void	hundred_numbers	(t_swap *swap);
void	joiner			(t_swap *swap, char *line);
void	p_opt			(t_swap *swap, int opt);
void	pa_opt			(t_swap *swap);
void	pb_opt			(t_swap *swap);
void	r_opt			(t_swap *swap, int opt);
void	ra_opt			(t_swap *swap);
void	rb_opt			(t_swap *swap);
void	rr_opt			(t_swap *swap, int opt);
void	rra_opt			(t_swap *swap);
void	rrb_opt			(t_swap *swap);
void	s_opt			(t_swap *swap, int opt);
void	s_opt3			(t_swap *swap);
void	sort			(t_swap *swap);
void	swapping		(t_swap *swap);
void	three_numbers	(t_swap *swap);

#endif