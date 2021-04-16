/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:59:46 by rarias-p          #+#    #+#             */
/*   Updated: 2021/04/07 16:24:30 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	compare(t_check *check)
{
	int	i;

	i = 0;
	if (check->c)
		printf("\033[0;31m");
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
	if (check->c)
		printf("\033[0;32m");
	printf("OK\n");
}
