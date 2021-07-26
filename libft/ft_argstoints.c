/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argstoints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:07:10 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/26 15:31:24 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_argstoints(int ac, char **av)
{
	char	**fchar;
	int		*fint;
	int		i;

	fchar = malloc(sizeof(char *) * (ac));
	if (!fchar)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
		fchar[i] = av[i + 1];
	fchar[ac - 1] = NULL;
	fint = malloc(sizeof(int *) * (ac));
	if (!fint)
		return (NULL);
	i = 0;
	while (fchar[i])
	{
		fint[i] = ft_atoi(fchar[i]);
		i++;
	}
	fint[ac - 1] = '\0';
	free (fchar);
	return (fint);
}
