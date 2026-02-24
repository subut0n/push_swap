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

void	sort_three(t_deque *stack[2])
{
	int	a;
	int	b;
	int	c;

	a = stack[A]->head->content;
	b = stack[A]->head->next->content;
	c = stack[A]->tail->content;
	if (a > b && b < c && a < c)
		act_and_write(stack, "sa");
	else if (a > b && b > c)
	{
		act_and_write(stack, "sa");
		act_and_write(stack, "rra");
	}
	else if (a > b && b < c && a > c)
		act_and_write(stack, "ra");
	else if (a < b && b > c && a < c)
	{
		act_and_write(stack, "sa");
		act_and_write(stack, "ra");
	}
	else if (a < b && b > c && a > c)
		act_and_write(stack, "rra");
}

static void	push_min_to_b(t_deque *stack[2])
{
	int	min;
	int	pos;

	min = find_min(stack[A]);
	pos = find_pos(stack[A], min);
	if (pos <= stack[A]->size / 2)
	{
		while (stack[A]->head->content != min)
			act_and_write(stack, "ra");
	}
	else
	{
		while (stack[A]->head->content != min)
			act_and_write(stack, "rra");
	}
	act_and_write(stack, "pb");
}

void	small_group(t_deque *stack[2])
{
	if (stack[A]->size == 2)
	{
		if (!is_stack_sorted(stack[A]))
			act_and_write(stack, "sa");
		return ;
	}
	while (stack[A]->size > 3)
		push_min_to_b(stack);
	sort_three(stack);
	while (stack[B]->size > 0)
		act_and_write(stack, "pa");
}
