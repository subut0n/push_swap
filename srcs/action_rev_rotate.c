/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rev_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:08:54 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:10:03 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_deque *stack)
{
	int	content;

	content = stack->tail->content;
	if (stack->size > 1)
	{
		deque_pop_back(stack);
		deque_add_front(stack, content);
	}
}

void	rrb(t_deque *stack)
{
	int	content;

	content = stack->tail->content;
	if (stack->size > 1)
	{
		deque_pop_back(stack);
		deque_add_front(stack, content);
	}
}

void	rrr(t_deque *stack[2])
{
	rra(stack[A]);
	rrb(stack[B]);
}
