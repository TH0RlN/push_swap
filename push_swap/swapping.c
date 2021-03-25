/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:28:59 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 16:59:57 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	joiner(t_swap *swap, char *line)
{
	char	*join;

	join = ft_strjoin(swap->inst, "\n");
	free (swap->inst);
	swap->inst = join;
	join = ft_strjoin(swap->inst, line);
	free (swap->inst);
	swap->inst = join;
	return ;
}*/

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
	{
		ft_free_int(swap->nums);
		free(swap);
		exit(0);
	}
}
