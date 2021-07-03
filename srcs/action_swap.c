/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:05:42 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:11:18 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_deque *stack)
{
	int	content[2];

	content[0] = stack->head->content;
	deque_pop_front(stack);
	content[1] = stack->head->content;
	deque_pop_front(stack);
	deque_add_front(stack, content[0]);
	deque_add_front(stack, content[1]);
}

void	sb(t_deque *stack)
{
	int	content[2];

	content[0] = stack->head->content;
	deque_pop_front(stack);
	content[1] = stack->head->content;
	deque_pop_front(stack);
	deque_add_front(stack, content[0]);
	deque_add_front(stack, content[1]);
}

void	ss(t_deque *stack[2])
{
	sa(stack[A]);
	sb(stack[B]);
}
