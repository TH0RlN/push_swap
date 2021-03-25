/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:57:34 by agianico          #+#    #+#             */
/*   Updated: 2021/03/24 17:55:22 by rarias-p         ###   ########.fr       */
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
	/**/printf("\n\n\n===== STEP: %3d =====\n", i);
	/**/printf("A:\n");
	/**/for (int k = 0; k < check->a_elem; k++)
	/**/	printf("\t%d:\t%d\n", k, check->nums[0][k]);
	/**/printf("B:\n");
	/**/for (int k = 0; k < check->b_elem; k++)
	/**/	printf("\t%d:\t%d\n", k, check->nums[1][k]);
	while (check->opts[i])
	{
		opt = check_opts(check->opts[i]);
		if (opt > 0 && opt < 4)
			s_opt(check, opt);
		else if (opt > 3 && opt < 6)
			p_opt(check, opt);
		else if (opt > 5 && opt < 9)
			r_opt(check, opt);
		else if (opt > 8 && opt < 12)
			rr_opt(check, opt);
		/**/printf("\n\n\n===== STEP: %3d =====\n\n", i + 1);
		/**/printf("A:\n");
		/**/for (int k = 0; k < check->a_elem; k++)
		/**/	printf("\t%d:\t%d\n", k, check->nums[0][k]);
		/**/printf("B:\n");
		/**/for (int k = 0; k < check->b_elem; k++)
		/**/	printf("\t%d:\t%d\n", k, check->nums[1][k]);
		i++;
	}
}
