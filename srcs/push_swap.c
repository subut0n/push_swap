/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:43:50 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/29 15:18:48 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	count_words(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static char	**build_argv(char **split, int *new_ac)
{
	int		wc;
	char	**new_av;
	int		i;

	wc = count_words(split);
	new_av = malloc(sizeof(char *) * (wc + 2));
	if (!new_av)
		return (NULL);
	new_av[0] = "push_swap";
	i = 0;
	while (i < wc)
	{
		new_av[i + 1] = split[i];
		i++;
	}
	new_av[wc + 1] = NULL;
	*new_ac = wc + 1;
	return (new_av);
}

static void	solve(t_deque *stack[2])
{
	if (is_stack_sorted(stack[A]))
		return ;
	if (stack[A]->size <= 5)
		small_group(stack);
	else
		big_group(stack);
}

int	main(int argc, char **argv)
{
	t_deque	*stack[2];
	char	**split;
	char	**new_av;

	split = NULL;
	new_av = NULL;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
		{
			if (split)
				free_split(split);
			return (0);
		}
		new_av = build_argv(split, &argc);
		argv = new_av;
	}
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
	solve(stack);
	deque_free(stack[A]);
	deque_free(stack[B]);
	if (split)
		free_split(split);
	if (new_av)
		free(new_av);
	return (0);
}
