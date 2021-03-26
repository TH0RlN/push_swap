/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:46:14 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/26 17:46:43 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = swap->b_elem;
	if (swap->b_elem > 1)
	{
		temp = swap->nums[1][swap->b_elem - 1];
		while (--i > 0)
			swap->nums[1][i] = swap->nums[1][i - 1];
		swap->nums[1][0] = temp;
	}
}

void	rra_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = swap->a_elem;
	if (swap->a_elem > 1)
	{
		temp = swap->nums[0][swap->a_elem - 1];
		while (--i > 0)
			swap->nums[0][i] = swap->nums[0][i - 1];
		swap->nums[0][0] = temp;
	}
}

void	rr_opt(t_swap *swap, int opt)
{
	if (opt == 9)
		rra_opt(swap);
	else if (opt == 10)
		rrb_opt(swap);
	else if (opt == 11)
	{
		rra_opt(swap);
		rrb_opt(swap);
	}
}
