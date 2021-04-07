/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:42:36 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/07 16:30:27 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_swap *swap)
{
	int	i;
	int	j;
	int	num;

	swap->pos = malloc(swap->a_elem * sizeof(int));
	i = -1;
	while (++i < swap->a_elem)
	{
		num = swap->nums[0][i];
		j = -1;
		swap->pos[i] = 0;
		while (++j < swap->a_elem)
		{
			if (num > swap->nums[0][j])
				swap->pos[i]++;
		}
	}
}

void	check_duplicates(t_swap *swap, char **argv)
{
	int	j;
	int	k;

	j = 1;
	while (argv[j])
	{
		swap->nums[0][j - 1] = ft_atoi(argv[j]);
		k = 1;
		while (j - (++k) >= 0)
		{
			if (swap->nums[0][j - 1] == swap->nums[0][j - k])
			{
				printf("Error\n");
				ft_exit(swap, 0);
			}
		}
		j++;
	}
}

void	stack_creater(t_swap *swap, int i, char **argv)
{
	int	k;

	k = i - 1;
	swap->chunk_num = 2;
	while (k > 2)
	{
		swap->chunk_num++;
		k = k / 2 + 1;
	}
	swap->nums = (int **)malloc(sizeof(int *) * swap->chunk_num);
	swap->chunks_len = malloc(sizeof(int) * i);
	swap->chunk_a = malloc(sizeof(int) * i);
	k = -1;
	while (++k < swap->chunk_num)
		swap->nums[k] = (int *)malloc(sizeof(int) * i);
	swap->a_elem = i - 1;
	swap->b_elem = 0;
	check_duplicates(swap, argv);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_swap	*swap;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
					|| (argv[i][j] == '-' && j == 0)))
				return (printf("Error\n"));
		}
	}
	swap = malloc(sizeof(t_swap));
	swap->inst = 0;
	stack_creater(swap, i, argv);
	swapping(swap);
	printf("%s", swap->inst);
	free(swap->inst);
	ft_exit(swap, 1);
}
