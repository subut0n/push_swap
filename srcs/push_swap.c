/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/31 15:40:34 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char **argv)
{
	t_deque *stack[2];
	int min_value;
	int pos;
	int sorted;

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
}