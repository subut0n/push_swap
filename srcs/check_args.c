/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:56:37 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/25 11:56:40 by addzikow         ###   ########lyon.fr   */
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

int	check_all_args(int ac, char **av)
{
	int i;

	if (ac == 1)
		return (1);
	i = 1;
	while (i < ac)
	{
		if (!check_arg(av[i]) || !check_limit(av[i]))
			return (0);
		i++;
	}
	return (1);
}