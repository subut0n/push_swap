/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:43:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/15 16:03:28 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*replace_crescendo(int *conv_args)
{
	int i;
	int *ret;
	int size;
	int smallest[2];
	int num;

	size = 0;
	while (conv_args[size])
		size++;
	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (NULL);
	num = 0;
	smallest[0] = conv_args[0];
	smallest[1] = INT_MIN;
	while (size != 0)
	{
		i = 0;
		while (conv_args[i])
		{
			if (conv_args[i] < smallest[0] && conv_args[i] > smallest[1])
				smallest[0] = conv_args[i];
			i++;
		}
		i = 0;
		while (conv_args[i] != smallest[0])
			i++;
		ret[i] = num++;
		smallest[1] = conv_args[i];
		smallest[0] = INT_MAX;
		size--;
	}
	return (ret);
}

void	init_stack(t_deque* stack, int size, int *convargs)
{
	int i;

	i = -1;
	while (++i < size)
		deque_add_back(stack, convargs[i]);
}

void parse(t_deque *stack, int ac, char **av)
{
	int size;
	int *converted_args;

	converted_args = ft_argstoints(ac, av);
	converted_args = replace_crescendo(converted_args);
	size = ac - 1;
	init_stack(stack, size, converted_args);
	free(converted_args); ///NE PAS OUBLIER
}