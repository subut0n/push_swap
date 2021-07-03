/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_big_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:43 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:27:54 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_it(t_deque *stack[2], int max_bits, int size)
{
	int	i[2];
	int	a_top;

	i[0] = -1;
	while (++i[0] < max_bits)
	{
		i[1] = -1;
		while (++i[1] < size)
		{
			a_top = stack[A]->head->content;
			if (((a_top >> i[0]) & 1) == 1)
				act_and_write(stack, "ra");
			else
				act_and_write(stack, "pb");
		}
		while (stack[B]->size > 0)
			act_and_write(stack, "pa");
	}
}

void	big_group(t_deque *stack[2])
{
	int	max_bits;
	int	size;
	int	max_num;

	max_bits = 0;
	size = stack[A]->size;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	solve_it(stack, max_bits, size);
}
