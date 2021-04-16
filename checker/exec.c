/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:57:34 by agianico          #+#    #+#             */
/*   Updated: 2021/04/06 15:51:48 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	opt_c(t_check *check, int i)
{
	int	k;

	k = -1;
	printf("\033[0;31m\n\n\n===== STEP: %3d =====\n", i);
	printf("\033[0;33mA:\n");
	while (++k < check->a_elem)
		printf("\t%d:\t%d\n", k, check->nums[0][k]);
	printf("\033[0;36mB:\n");
	k = -1;
	while (++k < check->b_elem)
		printf("\t%d:\t%d\n", k, check->nums[1][k]);
}

void	opt_v(t_check *check, int i)
{
	int	k;

	k = -1;
	printf("\n\n\n===== STEP: %3d =====\n", i);
	printf("A:\n");
	while (++k < check->a_elem)
		printf("\t%d:\t%d\n", k, check->nums[0][k]);
	printf("B:\n");
	k = -1;
	while (++k < check->b_elem)
		printf("\t%d:\t%d\n", k, check->nums[1][k]);
}

void	exec(t_check *check)
{
	int	i;
	int	opt;

	i = 0;
	if (check->c)
		opt_c(check, i);
	else if (check->v)
		opt_v(check, i);
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
		if (check->c)
			opt_c(check, i);
		else if (check->v)
			opt_v(check, i);
		i++;
	}
}
