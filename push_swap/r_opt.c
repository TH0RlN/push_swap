/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:34 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/26 19:17:19 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = -1;
	if (swap->b_elem > 1)
	{
		temp = swap->nums[1][0];
		while (++i < swap->b_elem - 1)
			swap->nums[1][i] = swap->nums[1][i + 1];
		swap->nums[1][i] = temp;
	}
}

void	ra_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = -1;
	if (swap->a_elem > 1)
	{
		temp = swap->nums[0][0];
		while (++i < swap->a_elem - 1)
			swap->nums[0][i] = swap->nums[0][i + 1];
		swap->nums[0][i] = temp;
	}
}

void	r_opt(t_swap *swap, int opt)
{
	if (opt == 6)
	{
		ra_opt(swap);
		joiner(swap, "ra\n");
	}
	else if (opt == 7)
	{
		rb_opt(swap);
		joiner(swap, "rb\n");
	}
	else if (opt == 8)
	{
		ra_opt(swap);
		rb_opt(swap);
		joiner(swap, "rr\n");
	}
}
