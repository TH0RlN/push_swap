/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agianico <agianico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:22:38 by agianico          #+#    #+#             */
/*   Updated: 2021/03/26 18:12:35 by agianico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers(t_swap *swap)
{
	swap->inst = ft_strdup("pb\npb\n");
	pb_opt(swap);
	pb_opt(swap);
	three_numbers(swap);
}