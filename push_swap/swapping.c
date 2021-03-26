/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:28:59 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/26 18:11:24 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	joiner(t_swap *swap, char *line)
{
	char	*join;

	if (!swap->inst)
		swap->inst = ft_strdup(line);
	else
	{
		join = ft_strjoin(swap->inst, line);
		free (swap->inst);
		swap->inst = join;
	}
}

void	ft_exit(t_swap *swap)
{
	ft_free_int(swap->nums);
	free(swap);
	exit(0);
}

int	compare(t_swap *swap)
{
	int	i;

	i = 0;
	if (swap->b_elem > 0)
		return (1);
	while (swap->a_elem - 1 > i)
	{
		if (swap->nums[0][i] > swap->nums[0][i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	swapping(t_swap *swap)
{
	if (!compare(swap))
		ft_exit(swap);
	else if (swap->a_elem == 2)
		swap->inst = ft_strdup("sa\n");
	else if (swap->a_elem == 3)
		three_numbers(swap);
	else if (swap->a_elem == 5)
		five_numbers(swap);
}
