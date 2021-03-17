/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:20:28 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/17 19:46:41 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	joiner(t_check *check, char *line)
{
	char	*join;

	join = ft_strjoin(check->vals, "\n");
	free (check->vals);
	check->vals = join;
	join = ft_strjoin(check->vals, line);
	free (check->vals);
	check->vals = join;
	return ;
}

void	checker(t_check *check)
{
	char	*line;

	line = 0;
	check->vals = 0;
	while (get_next_line(0, &line))
	{
		if (!check->vals)
			check->vals = ft_strdup(line);
		else
			joiner(check, line);
	}
	joiner(check, line);
	printf("%d\n", check->nums[0][0]);
	free(check);
}

void	stack_creater(t_check *check, int i, char **argv)
{
	int	 j;

	j = 1;
	check->nums = malloc(sizeof(int *) * 2);
	check->nums[0] = malloc(sizeof(int) * i - 2);
	check->nums[1] = 0;
	while (argv[j])
	{
		check->nums[0][j - 1] = ft_atoi(argv[j]);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_check	*check;

	check = malloc(sizeof(t_check *));
	i = 1;
	if (argc < 2)
		return (printf("Error\n"));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
					|| (argv[i][j] == '-' && j == 0)))
				return (printf("Error\n"));
			j++;
		}
		i++;
	}
	stack_creater(check, i, argv);
	checker(check);
}
