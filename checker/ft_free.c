/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:06 by agianico          #+#    #+#             */
/*   Updated: 2021/03/25 15:27:14 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}


void	ft_free_int(int **arr)
{
	free(arr[0]);
	free(arr[1]);
	free(arr);
}
