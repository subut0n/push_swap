/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:34:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/01 15:56:34 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_deque *stack)
{
	t_deque_list *temp;
	int i;

	temp = stack->head;
	i = 0;
	if (stack->size == 1)
		return (1);
	while (i < stack->size - 1)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int is_stack_reverse_sorted(t_deque *stack)
{
	t_deque_list *temp;
	int i;

	temp = stack->head;
	i = 0;
	while (i < stack->size - 1)
	{
		if (temp->content < temp->next->content)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}