/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:43:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/29 13:44:22 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	operate_crescendo(int *conv_args, int size, int value[2], int *ret)
{
	int	save;
	int	num;
	int	i;

	save = size;
	num = 0;
	while (size)
	{
		i = 0;
		while (i < save)
		{
			if (conv_args[i] < value[0] && conv_args[i] > value[1])
				value[0] = conv_args[i];
			i++;
		}
		i = 0;
		while (conv_args[i] != value[0])
			i++;
		ret[i] = num++;
		value[0] = INT_MAX;
		value[1] = conv_args[i];
		size--;
	}
}

static int	*replace_crescendo(int *conv_args, int size)
{
	int	*ret;
	int	value[2];

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (NULL);
	value[0] = conv_args[0];
	value[1] = INT_MIN;
	operate_crescendo(conv_args, size, value, ret);
	free(conv_args);
	return (ret);
}

void	init_stack(t_deque *stack, int size, int *convargs)
{
	int	i;

	i = -1;
	while (++i < size)
		deque_add_back(stack, convargs[i]);
}

void	parse(t_deque *stack, int ac, char **av)
{
	int	size;
	int	*converted_args;

	size = ac - 1;
	converted_args = ft_argstoints(ac, av);
	converted_args = replace_crescendo(converted_args, size);
	init_stack(stack, size, converted_args);
	free(converted_args);
}
