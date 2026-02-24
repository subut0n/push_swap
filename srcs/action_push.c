/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:10:43 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:10:58 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_deque *stack[2])
{
	int	content;

	if (stack[B]->size < 1)
		return ;
	content = stack[B]->head->content;
	deque_pop_front(stack[B]);
	deque_add_front(stack[A], content);
}

void	pb(t_deque *stack[2])
{
	int	content;

	if (stack[A]->size < 1)
		return ;
	content = stack[A]->head->content;
	deque_pop_front(stack[A]);
	deque_add_front(stack[B], content);
}
