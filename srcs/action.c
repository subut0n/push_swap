/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:07:36 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/27 15:29:19 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_deque *stack)
{
	void *content[2];

	content[0] = stack->head->content;
	deque_pop_front(stack,NULL);
	content[1] = stack->head->content;
	deque_add_front(stack, content[0]);
	deque_add_front(stack, content[1]);
}

void sb(t_deque *stack)
{
	void *content[2];

	content[0] = stack->head->content;
	deque_pop_front(stack,NULL);
	content[1] = stack->head->content;
	deque_add_front(stack, content[0]);
	deque_add_front(stack, content[1]);
}

void ss(t_deque *stack[2])
{
	sa(stack[A]);
	sb(stack[B]);
}

void pa(t_deque *stack[2])
{
	void *content;

	content = stack[B]->head->content;
	if (stack[B]->size > 0)
	{
		deque_pop_front(stack[B], NULL);
		deque_add_front(stack[A], content);
	}
}

void pb(t_deque *stack[2])
{
	void *content;

	content = stack[A]->head->content;
	if (stack[A]->size > 0)
	{
		deque_pop_front(stack[A], NULL);
		deque_add_front(stack[B], content);
	}
}

void ra(t_deque *stack)
{
	void *content;

	content = stack->head->content;
	if (stack->size > 1)
	{
		deque_pop_front(stack, NULL);
		deque_add_back(stack, content);
	}
}

void rb(t_deque *stack)
{
	void *content;

	content = stack->head->content;
	if (stack->size > 1)
	{
		deque_pop_front(stack, NULL);
		deque_add_back(stack, content);
	}
}

void rr(t_deque *stack[2])
{
	ra(stack[A]);
	rb(stack[B]);
}

void rra(t_deque *stack)
{
	void *content;

	content = stack->tail->content;
	if (stack->size > 1)
	{
		deque_pop_back(stack, NULL);
		deque_add_front(stack, content);
	}
}

void rrb(t_deque *stack)
{
	void *content;

	content = stack->tail->content;
	if (stack->size > 1)
	{
		deque_pop_back(stack, NULL);
		deque_add_front(stack, content);
	}
}

void rrr(t_deque *stack[2])
{
	rra(stack[A]);
	rrb(stack[B]);
}