/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/02 20:01:13 by antmarti         ###   ########.fr       */
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


void	hundred_numbers(t_swap *swap, int check)
{
	int	i;
	int	j;
	int	k;
	int	mdp;
	int	len_a;

	sort(swap);
	i = -1;
	while (++i < swap->a_elem)
		swap->nums[0][i] = swap->pos[i];
	i = -1;
	j = -1;
	k = -1;
	mdp = 0;
	while (swap->b_elem != 0 || check_order(swap->nums[0], swap->a_elem))
	{
		/*while (++j < swap->a_elem)
			printf("****NUM %d len:%d\n", swap->nums[0][j], swap->a_elem);*/
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
		else
		{
			if (!(check_rev_order(swap->nums[i + 2], swap->chunks_len[i])))
			{
				while (swap->chunks_len[i] > 0)
				{
					//printf("len: %d", swap->chunks_len[i]);
					chunk_pa(swap, i);
					pa_opt(swap);
				}
				i--;
			}
			else if (swap->chunks_len[i] < 3)
			{
				s_opt(swap, 1);
				chunk_pa(swap, swap->chunks_len[i]);
				pa_opt(swap);
				i--;
			}
			else
			{
				j = -1;
				i++;
				//printf("********%d\n", i);
				swap->chunks_len[i] = 0;
				mdp = get_mid_point(swap->nums[i + 2 - 1], swap->chunks_len[i - 1]);
				if (swap->chunks_len[i - 1] % 2 != 0)
					len_a = swap->chunks_len[i - 1] / 2 + 1;
				else
					len_a = swap->chunks_len[i - 1] / 2;
				check = 0;
				while (swap->chunks_len[i] < len_a - 1)
				{
					//printf("-----%d    %d\n", swap->chunks_len[i], len_a);
					while (++k < swap->chunks_len[i - 1])
					{
						if (swap->nums[1][k] > mdp)
							check++;
					}
					while (check < len_a - 1)
					{
						check = 0;
						while (++k < swap->chunks_len[i - 1])
						{
							if (swap->nums[1][k] > mdp)
								check++;
						}
						chunk_rrb(swap, i - 1);
						rr_opt(swap, 10);
					}
					if (swap->nums[i + 2 - 1][0] > mdp)
					{
						chunk_pb(swap, i);
						pa_opt(swap);
					}
					else
					{
						chunk_rb(swap, i - 1);
						r_opt(swap, 7);
					}
				}
			}
		}
		if (swap->a_elem < 3)
		{
			if (check_order(swap->nums[0], swap->a_elem))
				s_opt(swap, 1);
		}
		//printf("a elem: %d\n", swap->a_elem);
	}
}
