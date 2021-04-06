/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/06 13:56:45 by antmarti         ###   ########.fr       */
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
	}
	return (0);
}

int	get_mid_pos(int len, int *arr, int opt, int i)
{
	int	j;
	int	pos;

	j = -1;
	pos = 0;
	while (++j < len)
	{
		if (opt)
		{
			if (arr[j] < arr[i])
				pos++;
		}
		else
		{
			if (arr[j] > arr[i])
				pos++;
		}
	}
	return (pos);
}

int	get_mid_point(int *arr, int len, int opt)
{
	int	i;
	int	med;

	i = 0;
	if (len % 2)
		med = len / 2;
	else
		med = (len / 2) - 1;
	while (i < len)
	{
		if (get_mid_pos(len, arr, opt, i) == med)
			break ;
		i++;
	}
	return (arr[i]);
}

void	hundred_numbers(t_swap *swap)
{
	int	j;

	sort(swap);
	j = -1;
	while (++j < swap->a_elem)
		swap->nums[0][j] = swap->pos[j];
	swap->chunk_pos = -1;
	swap->chunk_a_len = 0;
	while (swap->b_elem != 0 || check_order(swap->nums[0], swap->a_elem))
	{
		if (check_order(swap->nums[0], swap->a_elem))
			unsorted_a(swap);
		else
		{
			if (swap->chunk_a_len)
				swap->chunk_a_len = 0;
			if (!(check_rev_order(swap->nums[swap->chunk_pos + 2],
						swap->chunks_len[swap->chunk_pos])))
				sorted_b(swap);
			else if (swap->chunks_len[swap->chunk_pos] < 3)
				chunk_2_numbers(swap);
			else
				mid_point_algo_2(swap);
		}
	}
}
