/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/02 18:14:35 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int *arr, int len)
{
	int	i;

	i = 0;
	while (len - 1 > i)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	//printf("******%d-----%d\n", arr[i], arr[i + 1]);
	}
	return (0);
}

int	get_mid_point(int *arr, int len)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < len)
	{
		sum += arr[i];
		i++;
	}
	return (sum / len);
}

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

void	chunk_pa(t_swap *swap, int num)
{
	int	i;

	i = 0;
	if (swap->chunks_len[num] >= 1)
	{
		while (i < swap->chunks_len[num])
		{
			swap->nums[num + 2][i] = swap->nums[num + 2][i + 1];
			i++;
		}
		swap->chunks_len[num]--;
	}
}

void	hundred_numbers(t_swap *swap)
{
	int	i;
	int	j;
	int	mdp;
	int	len_a;

	sort(swap);
	i = -1;
	while (++i < swap->a_elem)
		swap->nums[0][i] = swap->pos[i];
	i = -1;
	j = -1;
	mdp = 0;
	while (swap->b_elem != 0 || check_order(swap->nums[0], swap->a_elem))
	{
		//while (++j < swap->a_elem)
			//printf("****NUM %d len:%d\n", swap->nums[0][j], swap->a_elem);
		if (check_order(swap->nums[0], swap->a_elem))
		{
			j = -1;
			i++;
			//printf("********%d\n", i);
			swap->chunks_len[i] = 0;
			mdp = get_mid_point(swap->nums[0], swap->a_elem);
			if (swap->a_elem % 2 != 0)
				len_a = swap->a_elem / 2 + 1;
			else
				len_a = swap->a_elem / 2;
			while (swap->chunks_len[i] < len_a - 1)
			{
				//printf("-----%d    %d\n", swap->chunks_len[i], len_a);
				if (swap->nums[0][0] < mdp)
				{
					chunk_pb(swap, i);
					pb_opt(swap);
				}
				else if (swap->nums[0][swap->a_elem - 1]
					< mdp)
				{
					rr_opt(swap, 9);
					chunk_pb(swap, i);
					pb_opt(swap);
				}
				else
					r_opt(swap, 6);
			}
		}
		if (swap->a_elem < 3)
		{
			if (check_order(swap->nums[0], swap->a_elem))
				s_opt(swap, 1);
			break ;
		}
		//printf("a elem: %d\n", swap->a_elem);
	}
}
