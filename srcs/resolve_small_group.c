/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_small_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:46:33 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:29:41 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_exception(t_deque *stack[2])
{
	if (stack[A]->size == 3 && is_stack_reverse_sorted(stack[A]))
	{
		act_and_write(stack, "sa");
		act_and_write(stack, "rra");
		return (1);
	}
	if (stack[A]->size == 3
		&& ((stack[A]->head->content > stack[A]->head->next->content)
			&& (stack[A]->tail->content > stack[A]->head->content)))
	{
		act_and_write(stack, "sa");
		return (1);
	}
	return (0);
}

void	small_group(t_deque *stack[2])
{
	if (is_exception(stack))
		return ;
	while (stack[A]->size > 2)
	{
		if (find_pos(stack[A], find_min(stack[A])) <= ((stack[A]->size) / 2))
		{
			if (stack[A]->head->content == find_min(stack[A]))
				act_and_write(stack, "pb");
			else
				act_and_write(stack, "ra");
		}
		else
			act_and_write(stack, "rra");
	}
	if (!is_stack_sorted(stack[A]))
		act_and_write(stack, "sa");
	while (stack[B]->size > 0)
		act_and_write(stack, "pa");
}
