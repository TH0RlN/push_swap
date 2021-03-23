/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:57:34 by agianico          #+#    #+#             */
/*   Updated: 2021/03/23 18:18:33 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_opt3(t_check *check)
{
	s_opt(check, 1);
	s_opt(check, 2);
}

void	s_opt(t_check *check, int opt)
{
	int	temp;

	temp = 0;
	if (opt == 1)
	{
		if (check->a_elem > 1)
		{
			temp = check->nums[0][0];
			check->nums[0][0] = check->nums[0][1];
			check->nums[0][1] = temp;
			printf("%d\n", check->nums[0][0]);
			printf("%d\n", check->nums[0][1]);
		}
	}
	else if (opt == 2)
	{
		if (check->b_elem > 1)
		{
			temp = check->nums[1][0];
			check->nums[1][0] = check->nums[1][1];
			check->nums[1][1] = temp;
		}
	}
	else if (opt == 3)
		s_opt3(check);
}

void	exec(t_check *check)
{
	int	i;
	int	opt;

	i = 0;
	while (check->opts[i])
	{
		opt = check_opts(check->opts[i]);
		if (opt > 0 && opt < 4)
			s_opt(check, opt);
		else if (opt > 3 && opt < 6)
			p_opt(check, opt);
		i++;
	}
}
