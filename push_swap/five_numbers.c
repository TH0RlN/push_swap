/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:38 by agianico          #+#    #+#             */
/*   Updated: 2021/03/26 19:30:58 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int move_number(t_swap *swap, int *pos)
{
	int min;
	int i;

	min = 0;
	i = 0;
	while (swap->nums[0][i] < swap->a_elem)
	{
		if (swap->nums[1][0] < swap->nums[0][i])
		{
			if (!min)
			{
				min = swap->nums[0][i];
				*pos = i;
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

void	five_numbers(t_swap *swap)
{
	int	num;
	int pos;


	if (swap->a_elem == 5)
		pb_opt(swap);
	pb_opt(swap);
	three_numbers(swap);
	while (swap->b_elem > 0)
	{
		pos = 0;
		num = move_number(swap, &pos);
		if (pos == 1 && num)
			r_opt(swap, 6);
		else if (pos == 2 && num)
			rr_opt(swap, 9);
		pa_opt(swap);
		if (num == 0)
			r_opt(swap, 6);
	}
}
