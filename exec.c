/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:57:34 by agianico          #+#    #+#             */
/*   Updated: 2021/03/18 14:24:37 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_opt(t_check *check, int opt)
{
	int	temp;

	temp = 0;
	if (opt == 1)
	{
		temp = check->nums[0][0];
		check->nums[0][0] = check->nums[0][1];
		check->nums[0][1] = temp;
	}
	//printf("%d\n", check->nums[0][0]);
	//printf("%d\n", check->nums[0][1]);
}

void	exec(t_check *check)
{
	int	i;
	int	opt;

	i = 0;
	while(check->opts[i])
	{
		opt = check_opts(check->opts[i]);
		if (opt > 0 && opt < 4)
			s_opt(check, opt);
		i++;
	}
}