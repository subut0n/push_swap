/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:38:20 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/28 15:37:51 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double_list	*createList(void)
{
	double_list *racine;
	
	racine = malloc(sizeof(*racine));
	if (!racine)
		return (NULL);
	racine->previous = racine;
	racine->next = racine;
	return (racine);
}

void	addBefore(double_list *element, int content)
{
	double_list *new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return ;
	new_element->content = content;
	new_element->previous = element->previous;
	new_element->next = element;
	element->previous->next = new_element;
	element->previous = new_element; 
}

void	addAfter(double_list *element, int content)
{
	double_list *new_element;

	new_element = malloc(sizeof(*new_element));
	if (!new_element)
		return ;
	new_element->content = content;
	new_element->previous =  element->previous;
	new_element->next = element;
	element->next->previous = new_element;
	element->next = new_element;
}