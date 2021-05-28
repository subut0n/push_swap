/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:03:33 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/28 17:06:01 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque_list *init_deque_list(int content)
{
	t_deque_list *deque_list;

	deque_list = malloc(sizeof(t_deque_list));
	if (!deque_list)
		return (NULL);
	deque_list->content = content;
	deque_list->previous = NULL;
	deque_list->next = NULL;
	return (deque_list);
}

t_deque *init_deque(void)
{
	t_deque *deque;

	deque = malloc(sizeof(deque));
	if (!deque)
		return (NULL);
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
	return (deque);
}

void deque_add_front(t_deque *deque, int content)
{
	t_deque_list *temp;

	deque->size = deque->size + 1;
	temp = init_deque_list(content);
	if (!temp)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->next = deque->head;
	deque->head->previous = temp;
	deque->head = deque->head->previous;
}

void deque_add_back(t_deque *deque, int content)
{
	t_deque_list *temp;

	deque->size = deque->size + 1;
	temp = init_deque_list(content);
	if (!temp)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->previous = deque->tail;
	deque->tail->next = temp;
	deque->tail = deque->tail->next;
}

void deque_pop_front(t_deque *deque)
{
	t_deque_list *temp;

	if (deque->size < 1 || !deque->tail)
		return ;
	deque->size = deque->size - 1;
	temp = deque->head;
	deque->head = deque->head->next;
	if (deque->head)
		deque->head->previous = NULL;
	free(temp);
}

void	deque_pop_back(t_deque *deque)
{
	t_deque_list *temp;

	if (deque->size < 1 || !deque->tail)
		return ;
	deque->size = deque->size - 1;
	temp = deque->tail;
	deque->tail = deque->tail->previous;
	if (deque->tail)
		deque->tail->next = NULL;
	free(temp);
}