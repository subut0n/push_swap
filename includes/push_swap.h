/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:41:28 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/27 15:34:46 by addzikow         ###   ########lyon.fr   */
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

t_deque_list	*init_deque_list(void *ptr);
t_deque			*init_deque(void);
void			deque_add_front(t_deque *deque, void *ptr);
void			deque_add_back(t_deque *deque, void *ptr);
void			deque_pop_front(t_deque *deque, void (*f)(void *));
void			deque_pop_back(t_deque *deque, void (*f)(void *));

int 			check_limit(char *arg);
int 			check_arg(char *arg);
int				check_all_args(int ac, char **av);

void			sa(t_deque *stack);
void			sb(t_deque *stack);
void			ss(t_deque *stack[2]);
void			pa(t_deque *stack[2]);
void			pb(t_deque *stack[2]);
void			ra(t_deque *stack);
void			rb(t_deque *stack);
void			rr(t_deque *stack[2]);
void			rra(t_deque *stack);
void			rrb(t_deque *stack);
void			rrr(t_deque *stack[2]);


#endif