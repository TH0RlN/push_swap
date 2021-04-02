/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:42:36 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/02 17:46:38 by antmarti         ###   ########.fr       */
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

void	stack_creater(t_swap *swap, int i, char **argv)
{
	int	j;
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
	k = -1;
	while (++k < swap->chunk_num)
		swap->nums[k] = (int *)malloc(sizeof(int) * i);
	j = 1;
	swap->a_elem = i - 1;
	swap->b_elem = 0;
	swap->tot_elem = i - 1;
	while (argv[j])
	{
		swap->nums[0][j - 1] = ft_atoi(argv[j]);
		k = 1;
		while (j - (++k) >= 0)
		{
			if (swap->nums[0][j - 1] == swap->nums[0][j - k])
			{
				ft_free_int(swap, swap->nums);
				free(swap);
				exit(printf("Error\n"));
			}
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	swap->inst = 0;
	i = 1;
	if (argc < 2)
		return (0);
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
	stack_creater(swap, i, argv);
	swapping(swap);
	i = -1;
	/*while (++i < swap->a_elem)
		printf("Antes: %d\t\tDespués: %d\n", swap->nums[0][i], swap->order[i]);*/
	printf("%s", swap->inst);
	free(swap->inst);
	ft_exit(swap);
}
