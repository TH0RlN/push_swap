/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:35 by agianico          #+#    #+#             */
/*   Updated: 2021/03/26 18:12:21 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_swap *swap)
{
	sort(swap);
	if (swap->pos[0] == 0 && swap->pos[1] == 2 && swap->pos[2] == 1)
		joiner(swap, "sa\nra\n");
	else if (swap->pos[0] == 2 && swap->pos[1] == 1 && swap->pos[2] == 0)
		joiner(swap, "sa\nrra\n");
	else if (swap->pos[0] == 2 && swap->pos[1] == 0 && swap->pos[2] == 1)
		joiner(swap, "ra\n");
	else if (swap->pos[0] == 1 && swap->pos[1] == 2 && swap->pos[2] == 0)
		joiner(swap, "rra\n");
	else if (swap->pos[0] == 1 && swap->pos[1] == 0 && swap->pos[2] == 2)
		joiner(swap, "sa\n");
	free(swap->pos);
}
