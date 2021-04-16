/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:21:38 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/06 13:27:23 by antmarti         ###   ########.fr       */
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

void	chunk_rb(int *chunk, int len)
{
	int	i;
	int	temp;

	i = -1;
	if (len > 1)
	{
		temp = chunk[0];
		while (++i < len - 1)
			chunk[i] = chunk[i + 1];
		chunk[i] = temp;
	}
}

void	chunk_pa(int *chunk, int *len)
{
	int	i;
	int	j;

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

void	chunk_rrb(int *chunk, int len)
{
	int	i;
	int	temp;

	i = len;
	if (len > 1)
	{
		temp = chunk[len - 1];
		while (--i > 0)
			chunk[i] = chunk[i - 1];
		chunk[0] = temp;
	}
}
