/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/05 01:07:37 by antmarti         ###   ########.fr       */
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

int	check_rev_order(int *arr, int len)
{
	int	i;

	i = 0;
	while (len - 1 > i)
	{
		if (arr[i] < arr[i + 1])
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


void	hundred_numbers(t_swap *swap)
{
	int	j;
	int	mdp;
	
	sort(swap);
	j = -1;
	while (++j < swap->a_elem)
		swap->nums[0][j] = swap->pos[j];
	j = -1;
	mdp = 0;
	swap->chunk_pos = -1;
	swap->chunk_a_len = 0;
	while (swap->b_elem != 0 || check_order(swap->nums[0], swap->a_elem))
	{

		if (check_order(swap->nums[0], swap->a_elem))
		{
			if (!swap->chunk_a_len)
				mid_point_algo(swap, swap->nums[0], swap->a_elem);
			else
			{
				if (swap->chunk_a_len < 3)
				{
						s_opt(swap, 1);
						swap->chunk_a_len = 0;
				}
				else
					mid_point_algo(swap, swap->chunk_a,swap->chunk_a_len);
				//break ;
			}
		}
		else
		{
			if (!(check_rev_order(swap->nums[swap->chunk_pos + 2], swap->chunks_len[swap->chunk_pos])))
			{
				while (swap->chunks_len[swap->chunk_pos] > 0)
				{
					//printf("len: %d", swap->chunks_len[i]);
					chunk_pa(swap->nums[swap->chunk_pos + 2], &swap->chunks_len[swap->chunk_pos]);
					pa_opt(swap);
				}
				swap->chunk_pos--;
			}
			else if (swap->chunks_len[swap->chunk_pos] < 3)
			{
				j = -1;
				s_opt(swap, 2);
				while (++j < 2)
				{
					chunk_pa(swap->nums[swap->chunk_pos + 2], &swap->chunks_len[swap->chunk_pos]);
					pa_opt(swap);			
				}
				swap->chunk_pos--;
			}
			else
				mid_point_algo_2(swap);
		}
		if (swap->a_elem < 3)
		{
			if (check_order(swap->nums[0], swap->a_elem))
				s_opt(swap, 1);
		}
		/*j = -1;
		while (++j < swap->a_elem)
			printf("****NUM %d len:%d\n", swap->nums[0][j], swap->a_elem);
		j = -1;
		while (++j < swap->b_elem)
			printf("<<<<NUM %d len:%d\n", swap->nums[1][j], swap->b_elem);
		printf("MDP: %d CHUNK %d\n", mdp, swap->chunk_pos);*/
		//printf("a elem: %d\n", swap->a_elem);
	}
}
