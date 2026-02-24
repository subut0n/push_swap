/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:25:07 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/29 15:19:29 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_deque *stack)
{
	t_deque_list	*temp;
	int				i;
	int				min;

	temp = stack->head;
	min = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
		i++;
	}
	return (min);
}

int	find_max(t_deque *stack)
{
	t_deque_list	*temp;
	int				i;
	int				max;

	temp = stack->head;
	max = INT_MIN;
	i = 0;
	while (i < stack->size)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
		i++;
	}
	return (max);
}

int	find_pos(t_deque *stack, int nb)
{
	t_deque_list	*temp;
	int				count;

	temp = stack->head;
	count = 0;
	while (temp && temp->content != nb)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	find_closest_in_range(t_deque *stack, int low, int high)
{
	t_deque_list	*fwd;
	t_deque_list	*bwd;
	int				fi;
	int				bi;

	fwd = stack->head;
	bwd = stack->tail;
	fi = 0;
	bi = stack->size - 1;
	while (fi <= bi)
	{
		if (fwd->content >= low && fwd->content <= high)
			return (fi);
		if (bwd->content >= low && bwd->content <= high)
			return (bi);
		fwd = fwd->next;
		bwd = bwd->previous;
		fi++;
		bi--;
	}
	return (0);
}
