/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/20 15:26:45 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_limit(char *arg)
{
	long int nb;

	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int check_arg(char *arg)
{
	int i;
	
	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void simplification(int *stack, int size)
{
	int i;
	int less;
	int position;

	position = 1;
	less = stack[1];
	i = 1;
	while (stack[i])
	{
		if ()
	}
}

int main(int argc, char **argv)
{
	int i;
	int *stack[2];

	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i]) || !check_limit(argv[i]))
		{
			printf("Error");
			return (1);
		}
		i++;
	}
	stack[A] = malloc(sizeof(int) * argc);
	stack[B] = malloc(sizeof(int) * argc);
	stack[A][0] = argc - 1;
	stack[B][0] = 0;
	i = 1;
	while (i < argc)
	{
		stack[A][i] = ft_atoi(argv[i]);
		stack[B][i] = 0;
		printf("%d\n", stack[A][i]);
		i++;
	}
	printf("\n");
	simplification(stack[A], argc);
	//
	i = 1;
	while (i < argc)
	{
		printf("%d\n", stack[A][i]);
		i++;
	}
}