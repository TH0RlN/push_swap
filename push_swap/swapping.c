/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:28:59 by rarias-p          #+#    #+#             */
/*   Updated: 2021/03/25 17:26:03 by antmarti         ###   ########.fr       */
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

void	three_numbers(t_swap *swap)
{
	if (swap->pos[0] == 0 && swap->pos[1] == 2 && swap->pos[2] == 1)
		swap->inst = ft_strdup("sa\nra\n");
	else if (swap->pos[0] == 2 && swap->pos[1] == 1 && swap->pos[2] == 0)
		swap->inst = ft_strdup("sa\nrra\n");
	else if (swap->pos[0] == 2 && swap->pos[1] == 0 && swap->pos[2] == 1)
		swap->inst = ft_strdup("ra\n");
	else if (swap->pos[0] == 1 && swap->pos[1] == 2 && swap->pos[2] == 0)
		swap->inst = ft_strdup("rra\n");
	else if (swap->pos[0] == 1 && swap->pos[1] == 0 && swap->pos[2] == 2)
		swap->inst = ft_strdup("sa\n");
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
}
