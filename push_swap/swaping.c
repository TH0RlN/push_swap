/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:28:59 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 16:19:32 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	joiner(t_swap *swap, char *line)
{
	char	*join;

	join = ft_strjoin(swap->inst, "\n");
	free (swap->inst);
	swap->inst = join;
	join = ft_strjoin(swap->inst, line);
	free (swap->inst);
	swap->inst = join;
	return ;
}

void	compare(t_swap *swap)
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

void	swaping(t_swap *swap)
{
	int i;

	i = 0;
	while (i < swap->a_elem)
	{
			
	}
}