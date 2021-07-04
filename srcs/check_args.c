/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:56:37 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/04 16:03:29 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_limit(char *arg)
{
	long int	nb;

	nb = ft_atol(arg);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int	check_arg(char *arg)
{
	int	i;

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

int	check_dup(int ac, char **av)
{
	int	i;
	int	j;
	int	*value;

	value = malloc(sizeof(int) * (ac - 1));
	if (!value)
		return (0);
	i = -1;
	while (++i < ac - 1)
		value[i] = ft_atoi(av[i + 1]);
	i = -1;
	while (++i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (value[i] == value[j++])
				return (0);
		}
	}
	free(value);
	return (1);
}

int	check_all_args(int ac, char **av)
{
	int	i;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (!check_dup(ac, av))
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!check_arg(av[i]) || !check_limit(av[i]))
			return (0);
		i++;
	}
	return (1);
}
