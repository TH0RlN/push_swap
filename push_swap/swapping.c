/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:28:59 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/07 16:35:49 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	joiner(t_swap *swap, char *line)
{
	char	*join;

	if (!swap->inst)
		swap->inst = ft_strdup(line);
	else
	{
		join = ft_strjoin(swap->inst, line);
		free (swap->inst);
		swap->inst = join;
	}
}

void	ft_exit(t_swap *swap, int opt)
{
	ft_free_int(swap, swap->nums);
	free(swap->chunks_len);
	free(swap->chunk_a);
	if (opt)
		free(swap->pos);
	free(swap);
	exit(0);
}

int	compare(t_swap *swap)
{
	int	i;

	i = 0;
	if (swap->b_elem > 0)
		return (1);
	while (swap->a_elem - 1 > i)
	{
		if (swap->nums[0][i] > swap->nums[0][i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	swapping(t_swap *swap)
{
	if (!compare(swap))
		ft_exit(swap, 0);
	else if (swap->a_elem == 2)
	{
		printf("sa\n");
		ft_exit(swap, 0);
	}
	else if (swap->a_elem == 3)
		three_numbers(swap);
	else if (swap->a_elem == 5 || swap->a_elem == 4)
		five_numbers(swap);
	else
		hundred_numbers(swap);
}
