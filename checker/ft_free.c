/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:06 by agianico          #+#    #+#             */
/*   Updated: 2021/04/07 16:22:37 by antmarti         ###   ########.fr       */
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

void	ft_free(t_check *check, int opt)
{
	if (opt)
		ft_free_arr(check->opts);
	ft_free_int(check->nums);
	free(check);
	printf("\033[0m");
	exit(0);
}
