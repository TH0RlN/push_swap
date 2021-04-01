/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/04/01 19:18:16 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int *arr, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
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

int	move_number_rev(t_swap *swap, int *bool)
{
	int	min;
	int	i;
	int	pos;

	min = 0;
	i = 0;
	pos = 0;
	while (i < swap->b_elem)
	{
		if (swap->nums[0][0] > swap->nums[1][i])
		{
			if (!*bool)
			{
				min = swap->nums[1][i];
				pos = i;
				*bool = 1;
			}
			else if (min < swap->nums[1][i])
			{
				min = swap->nums[1][i];
				pos = i;
			}
		}
		i++;
	}
	return (pos);
}

void	order_b(t_swap *swap)
{
	int	pos;
	int	bool;

	bool = 0;
	pos = move_number_rev(swap, &bool);
	if (bool)
	{
		if (pos < swap->b_elem / 2)
		{
			while (pos > 0)
			{
				r_opt(swap, 7);
				pos--;
			}
		}
		else
		{
			while (pos < swap->b_elem)
			{
				rr_opt(swap, 10);
				pos++;
			}
		}
	}
	else
	{
		pos = 1;
		while (swap->nums[1][pos - 1] > swap->nums[1][pos]
			&& pos < swap->b_elem)
			pos++;
		if (pos != swap->b_elem)
		{
			if (pos < swap->b_elem / 2)
			{
				while (pos > 0)
				{
					r_opt(swap, 7);
					pos--;
				}
			}
			else
			{
				while (pos < swap->b_elem)
				{
					rr_opt(swap, 10);
					pos++;
				}
			}
		}
	}
	pb_opt(swap);
}

void	get_number_top(t_swap *swap, int i)
{
	i = 0;
	order_b(swap);
}

void	hundred_numbers(t_swap *swap)
{
	int	i;
	int	j;
	int	mdp;

	sort(swap);
	i = -1;
	while (++i < swap->a_elem)
		swap->nums[0][i] = swap->pos[i];
	i = -1;
	j = -1;
	mdp = 0;
	while (swap->b_elem != 0 || check_order(swap->nums[0], swap->a_elem))
	{
		if (check_order(swap->nums[0], swap->a_elem))
		{
			j = -1;
			mdp = get_mid_point(swap->nums[0], swap->a_elem);
			while (++j < swap->a_elem / 2)
			{
				if (swap->nums[0][0] < mdp)
					pb_opt(swap);
				else if (swap->nums[0][swap->a_elem - 1]
					< mdp)
				{
					rr_opt(swap, 9);
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
	}
}
