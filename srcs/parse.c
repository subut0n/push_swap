/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:43:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/31 15:54:12 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *ft_argstoints(int ac, char **av)
{
	char **fchar;
	int *fint;
	int i;

	fchar = malloc(sizeof(char *) * (ac));
	if (!fchar)
		return (NULL) ;
	i = 0;
	while (i < ac - 1)
	{
		fchar[i] = av[i + 1];
		i++;
	}
	fchar[ac - 1] = NULL;
	fint = malloc(sizeof(int *) * (ac));
	if (!fint)
		return(NULL);
	i = 0;
	while (fchar[i])
	{
		fint[i] = ft_atoi(fchar[i]);
		i++;
	}
	fint[ac - 1] = '\0';
	return (fint);
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
	int i;

	converted_args = ft_argstoints(ac, av);
	size = ac - 1;
	init_stack(stack, size, converted_args);
	i = 0;
	printf("head = %d\n", stack->head->content);
	printf("tail = %d\n", stack->tail->content);
	printf("size = %d\n", stack->size);
	free(converted_args); ///NE PAS OUBLIER
}