/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:36:30 by agianico          #+#    #+#             */
/*   Updated: 2021/03/26 17:47:23 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_opt3(t_swap *swap)
{
	s_opt(swap, 1);
	s_opt(swap, 2);
	joiner(swap, "ss\n");
}

void	s_opt(t_swap *swap, int opt)
{
	int	temp;

	temp = 0;
	if (opt == 1)
	{
		if (swap->a_elem > 1)
		{
			temp = swap->nums[0][0];
			swap->nums[0][0] = swap->nums[0][1];
			swap->nums[0][1] = temp;
		}
		joiner(swap, "sa\n");
	}
	else if (opt == 2)
	{
		if (swap->b_elem > 1)
		{
			temp = swap->nums[1][0];
			swap->nums[1][0] = swap->nums[1][1];
			swap->nums[1][1] = temp;
		}
		joiner(swap, "sb\n");
	}
	else if (opt == 3)
		s_opt3(swap);
}
