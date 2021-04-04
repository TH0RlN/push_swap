/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:46:14 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/05 00:41:04 by antmarti         ###   ########.fr       */
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
	{
		rra_opt(swap);
		joiner(swap, "rra\n");
	}
	else if (opt == 10)
	{
		rrb_opt(swap);
		joiner(swap, "rrb\n");
	}
	else if (opt == 11)
	{
		rra_opt(swap);
		rrb_opt(swap);
		joiner(swap, "rrr\n");
	}
}
