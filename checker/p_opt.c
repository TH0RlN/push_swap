/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:17:57 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_opt(t_check *check)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (check->b_elem >= 1)
	{
		temp = check->nums[1][0];
		while (i < check->b_elem)
		{
			check->nums[1][i] = check->nums[1][i + 1];
			i++;
		}
		check->b_elem--;
		i = check->a_elem;
		while (i > 0)
		{
			check->nums[0][i] = check->nums[0][i - 1];
			i--;
		}
		check->nums[0][0] = temp;
		check->a_elem++;
	}
}

void	pb_opt(t_check *check)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (check->a_elem >= 1)
	{
		temp = check->nums[0][0];
		while (i < check->a_elem - 1)
		{
			check->nums[0][i] = check->nums[0][i + 1];
			i++;
		}
		check->a_elem--;
		i = check->b_elem;
		while (i > 0)
		{
			check->nums[1][i] = check->nums[1][i - 1];
			i--;
		}
		check->nums[1][0] = temp;
		check->b_elem++;
	}	
}

void	p_opt(t_check *check, int opt)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (opt == 4)
		pa_opt(check);
	else if (opt == 5)
		pb_opt(check);
}
