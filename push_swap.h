/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:38:58 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/18 15:07:25 by agianico         ###   ########.fr       */
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

typedef struct s_check
{
	char		**opts;
	char		*vals;
	int			**nums;
	int			tot_elem;
	int			a_elem;
	int			b_elem;
}				t_check;

void			checker(t_check *check);
int				check_opts(char *opt);
void			exec(t_check *check);
int				get_next_line(int fd, char **line);
char			*ft_acc(char *file, char *buffer);
int				ft_atoi(const char *str);
int				ft_aux(char **line);
int				ft_checker(int fd, char **line, char **file, int ret);
void			ft_free_arr(char **arr);
void			ft_free_int(int **arr);
char			**ft_split(char *s, char c);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			stack_creater(t_check *check, int i, char **argv);
void			s_opt(t_check *check, int opt);

#endif