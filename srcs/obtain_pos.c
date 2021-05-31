/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:25:07 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/31 15:34:08 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_min(t_deque *stack)
{
	t_deque_list *temp;
	int i;
	int min;

	temp = stack->tail;
	min = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if(temp->content < min)
			min = temp->content;
		temp = temp->previous;
		i++;
	}
	return (min);
}

int		find_pos(t_deque *stack, int nb)
{
	t_deque_list *temp;
	int count;

	temp = stack->head;
	count = 0;
	while (temp->content != nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}