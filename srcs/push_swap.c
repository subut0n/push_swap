/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 00:19:51 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*stack[2];
	int		min_value;
	int		pos;
	int		sorted;

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
	else
		big_group(stack);
	deque_free(stack[A]);
	deque_free(stack[B]);
}
