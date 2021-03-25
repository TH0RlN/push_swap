/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:50:25 by agianico          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_opts(char *opt)
{
	if (!ft_strcmp("sa", opt))
		return (1);
	else if (!ft_strcmp("sb", opt))
		return (2);
	else if (!ft_strcmp("ss", opt))
		return (3);
	else if (!ft_strcmp("pa", opt))
		return (4);
	else if (!ft_strcmp("pb", opt))
		return (5);
	else if (!ft_strcmp("ra", opt))
		return (6);
	else if (!ft_strcmp("rb", opt))
		return (7);
	else if (!ft_strcmp("rr", opt))
		return (8);
	else if (!ft_strcmp("rra", opt))
		return (9);
	else if (!ft_strcmp("rrb", opt))
		return (10);
	else if (!ft_strcmp("rrr", opt))
		return (11);
	else
		return (0);
}
