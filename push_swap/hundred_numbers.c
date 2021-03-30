/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/30 18:02:00 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hundred_numbers(t_swap *swap)
{
	int i;
	
	sort(swap);
	i = -1;
	while (++i < swap->a_elem)
		swap->nums[0][i] = swap->pos[i];
	
}