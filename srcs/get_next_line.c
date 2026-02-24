/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:00:00 by addzikow          #+#    #+#             */
/*   Updated: 2021/07/29 16:00:00 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	read_char(char *c)
{
	return (read(0, c, 1));
}

int	get_next_line(char **line)
{
	char	c;
	char	*buf;
	int		i;
	int		ret;
	char	*tmp;

	buf = malloc(1);
	if (!buf)
		return (-1);
	buf[0] = '\0';
	i = 0;
	ret = read_char(&c);
	while (ret > 0 && c != '\n')
	{
		tmp = malloc(i + 2);
		if (!tmp)
		{
			free(buf);
			return (-1);
		}
		ft_memcpy(tmp, buf, i);
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(buf);
		buf = tmp;
		i++;
		ret = read_char(&c);
	}
	*line = buf;
	if (ret == 0 && i == 0)
	{
		free(buf);
		*line = NULL;
		return (0);
	}
	if (ret == 0)
		return (0);
	return (1);
}
