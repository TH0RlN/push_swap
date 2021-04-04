/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:21:38 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/04 23:15:55 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_pb(t_swap *swap, int num)
{
	int	i;

	i = swap->chunks_len[num];
	if (swap->a_elem >= 1)
	{
		while (i > 0)
		{
			swap->nums[num + 2][i] = swap->nums[num + 2][i - 1];
			i--;
		}
		swap->nums[num + 2][0] = swap->nums[0][0];
		swap->chunks_len[num]++;
	}
}

void	chunk_rb(t_swap *swap, int num)
{
	int	i;
	int	temp;

	i = -1;
	if (swap->chunks_len[num] > 1)
	{
		temp = swap->nums[num + 2][0];
		while (++i < swap->chunks_len[num] - 1)
			swap->nums[num + 2][i] = swap->nums[num + 2][i + 1];
		swap->nums[num + 2][i] = temp;
	}
}

void	chunk_pa(int *chunk, int *len)
{
	int	i;
	int j;

	i = 0;
	j = *len;
	if (j >= 1)
	{
		while (i < j)
		{
			chunk[i] = chunk[i + 1];
			i++;
		}
		j -= 1;
	}
	*len = j;
}

void	chunk_rrb(t_swap *swap, int num)
{
	int	i;
	int	temp;

	i = swap->chunks_len[num];
	if (swap->chunks_len[num] > 1)
	{
		temp = swap->nums[num + 2][swap->chunks_len[num] - 1];
		while (--i > 0)
			swap->nums[num + 2][i] = swap->nums[num + 2][i - 1];
		swap->nums[num + 2][0] = temp;
	}
}
