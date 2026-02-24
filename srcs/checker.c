/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:00:00 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/29 16:00:00 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid_op(char *line)
{
	if (!ft_strncmp(line, "sa", 3) || !ft_strncmp(line, "sb", 3)
		|| !ft_strncmp(line, "ss", 3) || !ft_strncmp(line, "pa", 3)
		|| !ft_strncmp(line, "pb", 3) || !ft_strncmp(line, "ra", 3)
		|| !ft_strncmp(line, "rb", 3) || !ft_strncmp(line, "rr", 3)
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4))
		return (1);
	return (0);
}

static void	exec_op(t_deque *stack[2], char *line)
{
	if (!ft_strncmp(line, "rra", 4))
		rra(stack[A]);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(stack[B]);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(stack);
	else if (!ft_strncmp(line, "sa", 3))
		sa(stack[A]);
	else if (!ft_strncmp(line, "sb", 3))
		sb(stack[B]);
	else if (!ft_strncmp(line, "ss", 3))
		ss(stack);
	else if (!ft_strncmp(line, "pa", 3))
		pa(stack);
	else if (!ft_strncmp(line, "pb", 3))
		pb(stack);
	else if (!ft_strncmp(line, "ra", 3))
		ra(stack[A]);
	else if (!ft_strncmp(line, "rb", 3))
		rb(stack[B]);
	else if (!ft_strncmp(line, "rr", 3))
		rr(stack);
}

static int	read_and_exec(t_deque *stack[2])
{
	char	*line;
	int		ret;

	ret = get_next_line(&line);
	while (ret > 0 || (ret == 0 && line))
	{
		if (!is_valid_op(line))
		{
			free(line);
			return (0);
		}
		exec_op(stack, line);
		free(line);
		ret = get_next_line(&line);
	}
	if (line)
		free(line);
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	setup_args(int *ac, char ***av, char ***split, char ***new_av)
{
	int		wc;
	int		i;

	*split = ft_split((*av)[1], ' ');
	if (!*split || !(*split)[0])
	{
		if (*split)
			free_split(*split);
		return (0);
	}
	wc = 0;
	while ((*split)[wc])
		wc++;
	*new_av = malloc(sizeof(char *) * (wc + 2));
	if (!*new_av)
		return (0);
	(*new_av)[0] = "checker";
	i = -1;
	while (++i < wc)
		(*new_av)[i + 1] = (*split)[i];
	(*new_av)[wc + 1] = NULL;
	*ac = wc + 1;
	*av = *new_av;
	return (1);
}

int	main(int argc, char **argv)
{
	t_deque	*stack[2];
	char	**split;
	char	**new_av;

	split = NULL;
	new_av = NULL;
	if (argc == 2 && !setup_args(&argc, &argv, &split, &new_av))
		return (0);
	if (!check_all_args(argc, argv))
	{
		write(2, "Error\n", 6);
		if (split)
			free_split(split);
		if (new_av)
			free(new_av);
		return (1);
	}
	stack[A] = init_deque();
	stack[B] = init_deque();
	parse(stack[A], argc, argv);
	if (!read_and_exec(stack))
		write(2, "Error\n", 6);
	else if (is_stack_sorted(stack[A]) && stack[B]->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	deque_free(stack[A]);
	deque_free(stack[B]);
	if (split)
		free_split(split);
	if (new_av)
		free(new_av);
	return (0);
}
