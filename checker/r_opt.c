/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:07:34 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rb_opt(t_check *check)
{
	int	i;
	int	temp;

	i = -1;
	if (check->b_elem > 1)
	{
		temp = check->nums[1][0];
		while (++i < check->b_elem - 1)
			check->nums[1][i] = check->nums[1][i + 1];
		check->nums[1][i] = temp;
	}
}

void	ra_opt(t_check *check)
{
	int	i;
	int	temp;

	i = -1;
	if (check->a_elem > 1)
	{
		temp = check->nums[0][0];
		while (++i < check->a_elem - 1)
			check->nums[0][i] = check->nums[0][i + 1];
		check->nums[0][i] = temp;
	}
}

void	r_opt(t_check *check, int opt)
{
	if (opt == 6)
		ra_opt(check);
	else if (opt == 7)
		rb_opt(check);
	else if (opt == 8)
	{
		ra_opt(check);
		rb_opt(check);
	}
}
