/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/08 09:59:01 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char **argv)
{
	t_deque *stack[2];
	int min_value;
	int pos;
	int sorted;

	// t_deque_list *temp;

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
	sorted = is_stack_sorted(stack[A]);
	if (sorted == 1)
		return (0);
	if (stack[A]->size <= 5)
		small_group(stack);
	// else
	// 	big_group(stack);
	//// afficher la liste
	// temp = stack[A]->head;
	// while (temp)
	// {
	// 	printf("ici = %d\n", temp->content);
	// 	temp = temp->next;
	// }
	/////////////////////
	deque_free(stack[A]);
	deque_free(stack[B]);
}

int	is_exception(t_deque *stack[2])
{
	if (stack[A]->size == 3 && is_stack_reverse_sorted(stack[A]))
	{
		act_and_write(stack, "sa");
		act_and_write(stack, "rra");
		return (1);
	}
	if (stack[A]->size == 3 &&
	((stack[A]->head->content > stack[A]->head->next->content) 
		&& (stack[A]->tail->content > stack[A]->head->content)))
	{
		act_and_write(stack, "sa");
		return (1);
	}
	return (0);
}

void	small_group(t_deque *stack[2])
{
	if (is_exception(stack))
		return ;
	while (stack[A]->size > 2)
	{
		if (find_pos(stack[A], find_min(stack[A])) <= ((stack[A]->size) / 2))
		{
			if (stack[A]->head->content == find_min(stack[A]))
				act_and_write(stack, "pb");
			else
				act_and_write(stack, "ra");
		}
		else
			act_and_write(stack, "rra");
	}
		if (!is_stack_sorted(stack[A]))
			act_and_write(stack, "sa");
		while (stack[B]->size > 0)
			act_and_write(stack, "pa");
}

// void	big_group(t_deque *stack[2])
// {

// }