/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/18 10:57:45 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(char *argv)
{
	int i;
	char *str;

	i = 0;
	str = malloc(sizeof(char *) * );
	while ()
}

int main(int argc, char * argv)
{
	int i;

	if (argc == 0)
		return (1);
	i = 0;	
	while (argv[i])
	{
		if (!check_args(argv[i]))
			return (1);
		i++;
	}	
}