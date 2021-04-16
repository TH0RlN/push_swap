/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:21:35 by agianico          #+#    #+#             */
/*   Updated: 2021/04/06 12:49:20 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_swap *swap)
{
	sort(swap);
	if (swap->pos[0] == 0 && swap->pos[1] == 2 && swap->pos[2] == 1)
	{
		s_opt(swap, 1);
		r_opt(swap, 6);
	}
	else if (swap->pos[0] == 2 && swap->pos[1] == 1 && swap->pos[2] == 0)
	{
		s_opt(swap, 1);
		rr_opt(swap, 9);
	}
	else if (swap->pos[0] == 2 && swap->pos[1] == 0 && swap->pos[2] == 1)
		r_opt(swap, 6);
	else if (swap->pos[0] == 1 && swap->pos[1] == 2 && swap->pos[2] == 0)
		rr_opt(swap, 9);
	else if (swap->pos[0] == 1 && swap->pos[1] == 0 && swap->pos[2] == 2)
		s_opt(swap, 1);
}
