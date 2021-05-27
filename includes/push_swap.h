/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:41:28 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/27 14:25:53 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

#include <limits.h>
#include <stdio.h>

enum stack
{
	A,
	B
};

typedef struct s_deque_list
{
	void *content;
	struct s_deque_list *previous;
	struct s_deque_list *next;
}	t_deque_list;

typedef struct s_deque
{
	t_deque_list *head;
	t_deque_list *tail;
	int	size;
}	t_deque;

int check_limit(char *arg);
int check_arg(char *arg);
int	check_all_args(int ac, char **av);

#endif