/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/26 15:26:50 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*stack[2];
	int		sorted;

	if (!check_all_args(argc, argv))
	{
		printf("Error");
		return (1);
	}
	stack[A] = init_deque();
	stack[B] = init_deque();
	parse(stack[A], argc, argv);
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
