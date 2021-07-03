/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:07:36 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:09:53 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_deque *stack)
{
	int	content;

	content = stack->head->content;
	if (stack->size > 1)
	{
		deque_pop_front(stack);
		deque_add_back(stack, content);
	}
}

void	rb(t_deque *stack)
{
	int	content;

	content = stack->head->content;
	if (stack->size > 1)
	{
		deque_pop_front(stack);
		deque_add_back(stack, content);
	}
}

void	rr(t_deque *stack[2])
{
	ra(stack[A]);
	rb(stack[B]);
}
