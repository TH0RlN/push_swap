/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:59:46 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 13:46:01 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	compare(t_check *check)
{
	int	i;

	i = 0;
	printf("\n\nEstas isntrucciones están:\t");
	if (check->b_elem > 0)
	{
		printf("KO\n");
		return ;
	}
	while (check->a_elem - 1 > i)
	{
		if (check->nums[0][i] > check->nums[0][i + 1])
		{
			printf("KO\n");
			return ;
		}
		i++;
	}
	printf("OK\n");
}
