/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:45:35 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/07 16:27:23 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_check
{
	int			**nums;
	char		*vals;
	int			b_elem;
	int			a_elem;
	char		**opts;
	int			v;
	int			c;
}				t_check;

void			checker			(t_check *check);
int				check_numbers	(char **argv, int i, int argc, int v);
int				check_opts		(char *opt);
void			compare			(t_check *check);
void			exec			(t_check *check);
int				get_next_line	(int fd, char **line);
char			*ft_acc			(char *file, char *buffer);
int				ft_atoi			(const char *str);
int				ft_aux			(char **line);
int				ft_checker		(int fd, char **line, char **file, int ret);
void			ft_free			(t_check *check, int opt);
void			ft_free_arr		(char **arr);
void			ft_free_int		(int **arr);
char			**ft_split		(char *s, char c);
char			*ft_strchr		(const char *s, int c);
int				ft_strcmp		(const char *s1, const char *s2);
char			*ft_strdup		(const char *s1);
char			*ft_strjoin		(char const *s1, char const *s2);
size_t			ft_strlen		(const char *s);
char			*ft_substr		(char const *s, unsigned int start, size_t len);
void			p_opt			(t_check *check, int opt);
void			pa_opt			(t_check *check);
void			pb_opt			(t_check *check);
void			r_opt			(t_check *check, int opt);
void			rr_opt			(t_check *check, int opt);
void			s_opt			(t_check *check, int opt);
void			s_opt3			(t_check *check);
void			stack_creater	(t_check *check, int i, char **argv);

#endif