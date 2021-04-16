/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:41:40 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/06 14:38:10 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unsorted_a(t_swap *swap)
{
	if (!swap->chunk_a_len)
	{
		if (swap->a_elem < 3)
			s_opt(swap, 1);
		else
			mid_point_algo(swap, swap->nums[0], swap->a_elem);
	}
	else
	{
		if (swap->chunk_a_len < 3)
		{
			s_opt(swap, 1);
			swap->chunk_a_len = 0;
		}
		else
			mid_point_algo(swap, swap->chunk_a, swap->chunk_a_len);
	}
}

void	sorted_b(t_swap *swap)
{
	while (swap->chunks_len[swap->chunk_pos] > 0)
	{
		chunk_pa(swap->nums[swap->chunk_pos + 2],
			&swap->chunks_len[swap->chunk_pos]);
		pa_opt(swap);
	}
	swap->chunk_pos--;
}

void	chunk_2_numbers(t_swap *swap)
{
	int	j;

	j = -1;
	s_opt(swap, 2);
	while (++j < 2)
	{
		chunk_pa(swap->nums[swap->chunk_pos + 2],
			&swap->chunks_len[swap->chunk_pos]);
		pa_opt(swap);
	}
	swap->chunk_pos--;
}

void	chunk_2_chunk(t_swap *swap)
{
	int	i;

	i = swap->chunk_a_len;
	if (swap->chunks_len[swap->chunk_pos] > 0)
	{
		while (i > 0)
		{
			swap->chunk_a[i] = swap->chunk_a[i - 1];
			i--;
		}
		swap->chunk_a[0] = swap->nums[swap->chunk_pos + 2][0];
		swap->chunk_a_len++;
	}
}
