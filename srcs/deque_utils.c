/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 00:13:59 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:15:37 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque_list	*init_deque_list(int content)
{
	t_deque_list	*deque_list;

	deque_list = malloc(sizeof(t_deque_list));
	if (!deque_list)
		return (NULL);
	deque_list->content = content;
	deque_list->previous = NULL;
	deque_list->next = NULL;
	return (deque_list);
}

t_deque	*init_deque(void)
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
	return (deque);
}

void	deque_free(t_deque *deque)
{
	while (deque->head)
		deque_pop_front(deque);
	free(deque);
}
