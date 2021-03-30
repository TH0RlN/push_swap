/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:59:13 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/30 22:32:47 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_number_rev(t_swap *swap, int *bool)
{
	int min;
	int i;
	int pos;

	min = 0;
	i = 0;
	pos = 0;
	while (i < swap->b_elem)
	{
		if (swap->nums[0][0] > swap->nums[1][i])
		{
			if (!*bool)
			{
				min = swap->nums[1][i];
				pos = i;
				*bool = 1;
			}
			else if (min < swap->nums[1][i])
			{
				min = swap->nums[1][i];
				pos = i;
			}
		}
		i++;
	}
	//printf("******%d y %d\n", min, *pos);
	return (pos);
}

void	order_b(t_swap *swap)
{
	int pos;
	int bool;
	
	bool = 0;
	pos = move_number_rev(swap, &bool);
	if (bool)
	{
		if (pos < swap->b_elem / 2)
		{
			while (pos > 0)
			{
				r_opt(swap, 7);
				pos--;	
			}
		}
		else
		{
			while (pos < swap->b_elem)
			{
				rr_opt(swap, 10);
				pos++;	
			}
		}
	}
	else
	{
		pos = 1;
		while (swap->nums[1][pos - 1] > swap->nums[1][pos] && pos < swap->b_elem)
			pos++;
		if (pos != swap->b_elem)
		{
			if (pos < swap->b_elem/ 2)
			{
				while (pos > 0)
				{
					r_opt(swap, 7);
					pos--;
				}
			}
			else
			{
				while (pos < swap->b_elem)
				{
					rr_opt(swap, 10);
					pos++;
				}
			}
		}
	}
	pb_opt(swap);
}

void	get_number_top(t_swap *swap, int i)
{
	while (i > 0)
	{
		r_opt(swap, 6);
		i--;	
	}
	order_b(swap);
}

void	get_number_bottom(t_swap *swap, int j)
{
	while (j < swap->a_elem)
	{
		rr_opt(swap, 9);
		j++;	
	}
	order_b(swap);
}

void	hundred_numbers(t_swap *swap)
{
	int i;
	int j;
	int k;
	
	sort(swap);
	i = -1;
	while (++i < swap->a_elem)
		swap->nums[0][i] = swap->pos[i];
	i = -1;
	k = 0;
	j = swap->a_elem;
	while (k < 100)
	{
		/*while ( ++i < swap->a_elem / 2 + 1)
		{
			if (swap->nums[0][i] < (k/50 + 1) * 50)
				break ;
		}
		while (--j > swap->a_elem / 2 - 1)
		{
			//printf("j: %d\n", j);
			if (swap->nums[0][j] < (k/50 + 1) * 50)
				break ;
		}
		//printf("*****%d     %d\n", i, j);
		if (i <= swap->a_elem - j)*/
		get_number_top(swap, i);
		/*else
			get_number_bottom(swap, j);*/
		k++;
	}
	while(swap->nums[1][0] != swap->b_elem - 1)
		rr_opt(swap, 10);	
	while(swap->a_elem < 100)
		pa_opt(swap);
}
