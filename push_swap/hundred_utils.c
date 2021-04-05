/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:34:39 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/05 17:13:26 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_chunk_a(t_swap *swap, int mdp, int len_a)
{
	int k;
	int check;
	
	k = -1;
	check = 0;
	while (++k < swap->chunk_a_len)
	{
		if (swap->nums[0][k] < mdp)
			check++;
	}
	while (check < len_a - 1)
	{
		check = 0;
		k = -1;
		while (++k < swap->chunk_a_len)
		{
			if (swap->nums[0][k] < mdp)
				check++;
		}
		chunk_rrb(swap->chunk_a, swap->chunk_a_len);
		rr_opt(swap, 9);
	}
}

void	arrange_chunk(t_swap *swap, int mdp, int len_a)
{
	int k;
	int check;
	
	k = -1;
	check = 0;
	while (++k < swap->chunks_len[swap->chunk_pos])
	{
		if (swap->nums[1][k] > mdp)
			check++;
	}
	while (check < len_a - 1)
	{
		check = 0;
		k = -1;
		while (++k < swap->chunks_len[swap->chunk_pos])
		{
			if (swap->nums[1][k] > mdp)
				check++;
		}
		chunk_rrb(swap->nums[swap->chunk_pos + 2], swap->chunks_len[swap->chunk_pos]);
		rr_opt(swap, 10);
	}
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

int		send_half_2(t_swap *swap, int mdp)
{
	int ret;
	
	ret = 0;
	if (swap->nums[swap->chunk_pos + 2][0] > mdp)
	{
		chunk_2_chunk(swap);
		chunk_pa(swap->nums[swap->chunk_pos + 2], &swap->chunks_len[swap->chunk_pos]);
		pa_opt(swap);
	}
	else
	{
		chunk_rb(swap->nums[swap->chunk_pos + 2], swap->chunks_len[swap->chunk_pos]);
		r_opt(swap, 7);
		ret++;
	}
	return (ret);
}


void	mid_point_algo_2(t_swap *swap)
{
	int len_a;
	int mdp;
	int rr;

	rr = 0;
	swap->chunk_a_len = 0;
	mdp = get_mid_point(swap->nums[swap->chunk_pos + 2], swap->chunks_len[swap->chunk_pos], 0);
	if (swap->chunks_len[swap->chunk_pos] % 2 != 0)
		len_a = swap->chunks_len[swap->chunk_pos] / 2 + 1;
	else
		len_a = swap->chunks_len[swap->chunk_pos] / 2;
	//arrange_chunk(swap, mdp, len_a);
	while (swap->chunk_a_len < len_a - 1)
		rr += send_half_2(swap, mdp);
	while (rr > 0)
	{
		chunk_rrb(swap->nums[swap->chunk_pos + 2], swap->chunks_len[swap->chunk_pos]);
		rr_opt(swap, 10);
		rr--;
	}	
}

int	send_half(t_swap *swap, int mdp)
{
	int ret;

	ret = 0;
	if (swap->nums[0][0] < mdp)
	{
		if(swap->chunk_a_len)
			chunk_pa(swap->chunk_a, &swap->chunk_a_len);
		chunk_pb(swap, swap->chunk_pos);
		pb_opt(swap);
	}
	else if (swap->nums[0][swap->a_elem - 1]
		< mdp && !swap->chunk_a_len)
	{
		rr_opt(swap, 9);
		chunk_pb(swap, swap->chunk_pos);
		pb_opt(swap);
	}
	else
	{
		if(swap->chunk_a_len)
		{
			chunk_rb(swap->chunk_a, swap->chunk_a_len);	
			ret++;	
		}
		r_opt(swap, 6);
	}
	return (ret);
}


void	mid_point_algo(t_swap *swap, int *arr, int len)
{
	int len_a;
	int mdp;
	int rr;
	
	rr = 0;
	swap->chunk_pos++;
	swap->chunks_len[swap->chunk_pos] = 0;
	mdp = get_mid_point(arr, len, 1);
	if (len % 2 != 0)
		len_a = (len / 2) + 1;
	else
		len_a = len / 2;
	while (swap->chunks_len[swap->chunk_pos] < len_a - 1)
		rr += send_half(swap, mdp);
	while (rr > 0)
	{
		chunk_rrb(swap->chunk_a, swap->chunk_a_len);
		rr_opt(swap, 9);
		rr--;
	}	
}