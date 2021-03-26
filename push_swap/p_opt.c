/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:17:57 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/26 19:15:30 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (swap->b_elem >= 1)
	{
		temp = swap->nums[1][0];
		while (i < swap->b_elem)
		{
			swap->nums[1][i] = swap->nums[1][i + 1];
			i++;
		}
		swap->b_elem--;
		i = swap->a_elem;
		while (i > 0)
		{
			swap->nums[0][i] = swap->nums[0][i - 1];
			i--;
		}
		swap->nums[0][0] = temp;
		swap->a_elem++;
		joiner(swap, "pa\n");
	}
}

void	pb_opt(t_swap *swap)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (swap->a_elem >= 1)
	{
		temp = swap->nums[0][0];
		while (i < swap->a_elem - 1)
		{
			swap->nums[0][i] = swap->nums[0][i + 1];
			i++;
		}
		swap->a_elem--;
		i = swap->b_elem;
		while (i > 0)
		{
			swap->nums[1][i] = swap->nums[1][i - 1];
			i--;
		}
		swap->nums[1][0] = temp;
		swap->b_elem++;
		joiner(swap, "pb\n");
	}
}

void	p_opt(t_swap *swap, int opt)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (opt == 4)
		pa_opt(swap);
	else if (opt == 5)
		pb_opt(swap);
}
