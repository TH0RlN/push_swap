/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:38 by agianico          #+#    #+#             */
/*   Updated: 2021/04/06 13:31:21 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_number(t_swap *swap, int *pos, int *bool)
{
	int	min;
	int	i;

	min = 0;
	i = 0;
	while (i < swap->a_elem)
	{
		if (swap->nums[1][0] < swap->nums[0][i])
		{
			if (!*bool)
			{
				min = swap->nums[0][i];
				*pos = i;
				*bool = 1;
			}
			else if (min > swap->nums[0][i])
			{
				min = swap->nums[0][i];
				*pos = i;
			}
		}
		i++;
	}
	return (min);
}

void	five_pos(t_swap *swap, int pos)
{
	if (pos == 1)
	{
		r_opt(swap, 6);
		pa_opt(swap);
		rr_opt(swap, 9);
	}
	else if (pos == 2 || pos == 3)
	{
		rr_opt(swap, 9);
		if (swap->a_elem == 4 && pos == 2)
			rr_opt(swap, 9);
		pa_opt(swap);
		r_opt(swap, 6);
		r_opt(swap, 6);
		if (swap->a_elem == 5 && pos == 2)
			r_opt(swap, 6);
	}
}

void	five_numbers(t_swap *swap)
{
	int	num;
	int	pos;
	int	bool;

	if (swap->a_elem == 5)
		pb_opt(swap);
	pb_opt(swap);
	three_numbers(swap);
	while (swap->b_elem > 0)
	{
		pos = 0;
		bool = 0;
		num = move_number(swap, &pos, &bool);
		if (!bool)
		{
			pa_opt(swap);
			r_opt(swap, 6);
		}
		else if (pos == 1 || pos == 2 || pos == 3)
			five_pos(swap, pos);
		else
			pa_opt(swap);
	}
}
