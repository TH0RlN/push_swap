/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_opt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:36:30 by agianico          #+#    #+#             */
/*   Updated: 2021/03/26 17:37:08 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
