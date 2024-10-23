/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:22:29 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:22:31 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_position(t_lst *head, t_lst *to_find)
{
	t_lst	*tempo;
	size_t	position;

	tempo = head;
	position = 0;
	while (tempo->next != head)
	{
		if (tempo == to_find)
			break ;
		position++;
		tempo = tempo->next;
	}
	return (position);
}

t_lst	*find_greatest(t_lst *head)
{
	t_lst	*tempo;
	t_lst	*greatest;

	greatest = NULL;
	tempo = head;
	while (tempo->next != head)
	{
		if (!greatest || tempo->value > greatest->value)
			greatest = tempo;
		tempo = tempo->next;
	}
	if (!greatest || tempo->value > greatest->value)
		greatest = tempo;
	return (greatest);
}

t_lst	*find_lowest(t_lst *head)
{
	t_lst	*tempo;
	t_lst	*lowest;

	lowest = NULL;
	tempo = head;
	while (tempo->next != head)
	{
		if (!lowest || tempo->value < lowest->value)
			lowest = tempo;
		tempo = tempo->next;
	}
	if (!lowest || tempo->value < lowest->value)
		lowest = tempo;
	return (lowest);
}

void	set_moves_to_top_count(t_lst *head, t_lst *target,
		size_t moves_count[2])
{
	size_t	position;

	position = get_position(head, target);
	moves_count[STANDARD] = position;
	moves_count[REVERSE] = ft_lst_size(head) - position;
}
