/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matchmaking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:44 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:21:45 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*find_nearest_low(t_lst *head, int reference_value)
{
	t_lst	*tempo;
	t_lst	*target;
	size_t	lowest_diff;

	lowest_diff = MY_UINT_MAX;
	tempo = head;
	target = NULL;
	while (tempo->next != head)
	{
		if (tempo->value < reference_value)
		{
			if (get_difference(tempo->value, reference_value) < lowest_diff)
			{
				lowest_diff = get_difference(tempo->value, reference_value);
				target = tempo;
			}
		}
		tempo = tempo->next;
	}
	if (tempo->value < reference_value)
		if (get_difference(tempo->value, reference_value) < lowest_diff)
			target = tempo;
	if (!target)
		target = find_greatest(head);
	return (target);
}

t_lst	*find_nearest_high(t_lst *head, int reference_value)
{
	t_lst	*tempo;
	t_lst	*target;
	size_t	lowest_diff;

	lowest_diff = MY_UINT_MAX;
	tempo = head;
	target = NULL;
	while (tempo->next != head)
	{
		if (tempo->value > reference_value)
		{
			if (get_difference(tempo->value, reference_value) < lowest_diff)
			{
				lowest_diff = get_difference(tempo->value, reference_value);
				target = tempo;
			}
		}
		tempo = tempo->next;
	}
	if (tempo->value > reference_value)
		if (get_difference(tempo->value, reference_value) < lowest_diff)
			target = tempo;
	if (!target)
		target = find_lowest(head);
	return (target);
}
