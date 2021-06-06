/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/06 16:27:49 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char **argv)
{
	t_deque *stack[2];
	int min_value;
	int pos;
	int sorted;

	t_deque_list *temp;

	stack[A] = init_deque();
	stack[B] = init_deque();
	if (!check_all_args(argc, argv))
	{
		printf("Error");
		return (1);
	}
	parse(stack[A], argc, argv);
	min_value = find_min(stack[A]);
	pos = find_pos(stack[A], min_value);
	printf("min = %d\n", min_value);
	printf("pos = %d\n", pos);
	sorted = is_stack_sorted(stack[A]);
	printf("sorted = %d\n", sorted);
	if (sorted == 1)
		return (0);
	if (stack[A]->size <= 5)
		small_group(stack);
	//// afficher la liste
	temp = stack[A]->head;
	while (temp)
	{
		printf("ici = %d\n", temp->content);
		temp = temp->next;
	}
	/////////////////////
	deque_free(stack[A]);
	deque_free(stack[B]);
}

void	small_group(t_deque *stack[2])
{
	while (stack[A]->size > 2)
	{
		if (find_pos(stack[A], find_min(stack[A])) <= ((stack[A]->size) / 2))
		{
			if (stack[A]->head->content == find_min(stack[A]))
				pb(stack);
			else
				ra(stack[A]);
		}
		else
			rra(stack[A]);
		}
		if (!is_stack_sorted(stack[A]))
			sa(stack[A]);
		while (stack[B]->size > 0)
			pa(stack);
}

