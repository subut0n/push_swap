/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:41:28 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/07 14:41:02 by addzikow         ###   ########.fr       */
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

///////////////////////////////////////////////////////////////////////////
typedef struct s_deque_list
{
	int content;
	struct s_deque_list *previous;
	struct s_deque_list *next;
}	t_deque_list;

typedef struct s_deque
{
	t_deque_list *head;
	t_deque_list *tail;
	int	size;
}	t_deque;

t_deque_list	*init_deque_list(int content);
t_deque			*init_deque(void);
void			deque_add_front(t_deque *deque, int content);
void			deque_add_back(t_deque *deque, int content);
void			deque_pop_front(t_deque *deque);
void			deque_pop_back(t_deque *deque);
void			deque_free(t_deque *deque);

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
///////////////////////////////////////////////////////////////////////////

int 			check_limit(char *arg);
int 			check_arg(char *arg);
int				check_dup(int ac, char **av);
int				check_all_args(int ac, char **av);

void			parse(t_deque *stack, int ac, char **av);

int				find_min(t_deque *stack);
int				find_pos(t_deque *stack, int nb);

int				is_stack_sorted(t_deque *stack);
int				is_stack_reverse_sorted(t_deque *stack);

void    do_push(t_deque *stack[2], char *str);
void    do_swap(t_deque *stack[2], char *str);
void    do_rotate(t_deque *stack[2], char *str);
void    do_rev_rotate(t_deque *stack[2], char *str);
void	act_and_write(t_deque *stack[2], char *str);

void			small_group(t_deque *stack[2]);
void			big_group(t_deque *stack[2]);

#endif