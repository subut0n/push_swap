/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/28 09:59:13 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (!check_all_args(argc, argv))
	{
		printf("Error");
		return (1);
	}
	parse(argc,argv);
}