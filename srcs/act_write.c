/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:07:05 by addzikow          #+#    #+#             */
/*   Updated: 2021/06/08 10:01:57 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_push(t_deque *stack[2], char *str)
{
    if (!ft_strncmp(str, "pa", 3))
	{
		pa(stack);
		write(1, "pa", 2);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "pb", 2))
	{
		pb(stack);
		write(1, "pb", 2);
		write(1, "\n", 1);
	}
}

void    do_swap(t_deque *stack[2], char *str)
{
    if (!ft_strncmp(str, "sa", 3))
	{
		sa(stack[A]);
		write(1, "sa", 2);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "sb", 3))
	{
		sb(stack[B]);
		write(1, "sb", 2);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "ss", 3))
	{
		sa(stack[A]);
		sb(stack[B]);
		write(1, "ss", 2);
		write(1, "\n", 1);
	}
}

void    do_rotate(t_deque *stack[2], char *str)
{
    if (!ft_strncmp(str, "ra", 3))
	{
		ra(stack[A]);
		write(1, "ra", 2);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "rb", 3))
	{
		rb(stack[B]);
		write(1, "rb", 2);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "rr", 3))
	{
		ra(stack[A]);
		rb(stack[B]);
		write(1, "rr", 2);
		write(1, "\n", 1);
	}
}

void    do_rev_rotate(t_deque *stack[2], char *str)
{
    if (!ft_strncmp(str, "rra", 4))
	{
		rra(stack[A]);
		write(1, "rra", 3);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "rrb", 4))
	{
		rrb(stack[B]);
		write(1, "rrb", 3);
		write(1, "\n", 1);
	}
	if (!ft_strncmp(str, "rrr", 4))
	{
		rra(stack[A]);
		rrb(stack[B]);
		write(1, "rrr", 3);
		write(1, "\n", 1);
	}
}

void	act_and_write(t_deque *stack[2], char *str)
{
    if ((!ft_strncmp(str, "pa", 3))|| (!ft_strncmp(str, "pb", 3)))
        do_push(stack, str);
    if ((!ft_strncmp(str, "sa", 3))|| (!ft_strncmp(str, "sb", 3)) || (!ft_strncmp(str, "ss", 3)))
        do_swap(stack, str);
    if ((!ft_strncmp(str, "ra", 3)) || (!ft_strncmp(str, "rb", 3)) || (!ft_strncmp(str, "rr", 3)))
        do_rotate(stack, str);
    if ((!ft_strncmp(str, "rra", 4)) || (!ft_strncmp(str, "rrb", 4)) || (!ft_strncmp(str, "rrr", 4)))
        do_rev_rotate(stack, str);
}