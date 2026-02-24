/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_big_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:47:43 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/26 15:27:52 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_target_pos_b(t_deque *b, int val)
{
	t_deque_list	*cur;
	int				best_pos;
	int				best_val;
	int				i;

	best_val = -1;
	best_pos = 0;
	cur = b->head;
	i = -1;
	while (++i < b->size)
	{
		if (cur->content < val && cur->content > best_val)
		{
			best_val = cur->content;
			best_pos = i;
		}
		cur = cur->next;
	}
	if (best_val == -1)
		return (find_pos(b, find_max(b)));
	return (best_pos);
}

static int	get_target_pos_a(t_deque *a, int val)
{
	t_deque_list	*cur;
	int				best_pos;
	int				best_val;
	int				i;

	best_val = INT_MAX;
	best_pos = 0;
	cur = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (cur->content > val && cur->content < best_val)
		{
			best_val = cur->content;
			best_pos = i;
		}
		cur = cur->next;
	}
	if (best_val == INT_MAX)
		return (find_pos(a, find_min(a)));
	return (best_pos);
}

static int	calc_cost(int pos_a, int size_a, int pos_b, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (pos_a <= size_a / 2)
		cost_a = pos_a;
	else
		cost_a = size_a - pos_a;
	if (pos_b <= size_b / 2)
		cost_b = pos_b;
	else
		cost_b = size_b - pos_b;
	if ((pos_a <= size_a / 2) == (pos_b <= size_b / 2))
		return (1 + cost_a + cost_b
			- (cost_a < cost_b) * cost_a
			- (cost_b <= cost_a) * cost_b);
	return (1 + cost_a + cost_b);
}

static void	find_cheapest(t_deque *s[2], int *best)
{
	t_deque_list	*cur;
	int				i;
	int				pos_b;
	int				cost;

	best[2] = INT_MAX;
	cur = s[A]->head;
	i = -1;
	while (++i < s[A]->size)
	{
		pos_b = get_target_pos_b(s[B], cur->content);
		cost = calc_cost(i, s[A]->size, pos_b, s[B]->size);
		if (cost < best[2])
		{
			best[0] = i;
			best[1] = pos_b;
			best[2] = cost;
		}
		cur = cur->next;
	}
}

static void	do_rotations(t_deque *s[2], int pos_a, int pos_b)
{
	int	rev_a;
	int	rev_b;

	rev_a = (pos_a > s[A]->size / 2);
	rev_b = (pos_b > s[B]->size / 2);
	while (pos_a > 0 && pos_b > 0 && !rev_a && !rev_b)
	{
		act_and_write(s, "rr");
		pos_a--;
		pos_b--;
	}
	while (pos_a < s[A]->size && pos_b < s[B]->size && rev_a && rev_b)
	{
		act_and_write(s, "rrr");
		pos_a++;
		pos_b++;
	}
	while (pos_a > 0 && !rev_a && pos_a--)
		act_and_write(s, "ra");
	while (pos_a < s[A]->size && rev_a && pos_a++)
		act_and_write(s, "rra");
	while (pos_b > 0 && !rev_b && pos_b--)
		act_and_write(s, "rb");
	while (pos_b < s[B]->size && rev_b && pos_b++)
		act_and_write(s, "rrb");
}

static void	rotate_to_pos(t_deque *s[2], int pos, char *r, char *rr)
{
	int	size;

	if (!ft_strncmp(r, "ra", 3))
		size = s[A]->size;
	else
		size = s[B]->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			act_and_write(s, r);
	}
	else
	{
		while (pos++ < size)
			act_and_write(s, rr);
	}
}

static void	push_back_to_a(t_deque *s[2])
{
	int	target;

	while (s[B]->size > 0)
	{
		target = get_target_pos_a(s[A], s[B]->head->content);
		rotate_to_pos(s, target, "ra", "rra");
		act_and_write(s, "pa");
	}
	target = find_pos(s[A], find_min(s[A]));
	rotate_to_pos(s, target, "ra", "rra");
}

void	big_group(t_deque *stack[2])
{
	int	best[3];

	act_and_write(stack, "pb");
	act_and_write(stack, "pb");
	while (stack[A]->size > 3)
	{
		find_cheapest(stack, best);
		do_rotations(stack, best[0], best[1]);
		act_and_write(stack, "pb");
	}
	sort_three(stack);
	push_back_to_a(stack);
}
