/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:46:14 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrb_opt(t_check *check)
{
	int	i;
	int	temp;

	i = check->b_elem;
	if (check->b_elem > 1)
	{
		temp = check->nums[1][check->b_elem - 1];
		while (--i > 0)
			check->nums[1][i] = check->nums[1][i - 1];
		check->nums[1][0] = temp;
	}
}

void	rra_opt(t_check *check)
{
	int	i;
	int	temp;

	i = check->a_elem;
	if (check->a_elem > 1)
	{
		temp = check->nums[0][check->a_elem - 1];
		while (--i > 0)
			check->nums[0][i] = check->nums[0][i - 1];
		check->nums[0][0] = temp;
	}
}

void	rr_opt(t_check *check, int opt)
{
	if (opt == 9)
		rra_opt(check);
	else if (opt == 10)
		rrb_opt(check);
	else if (opt == 11)
	{
		rra_opt(check);
		rrb_opt(check);
	}
}
