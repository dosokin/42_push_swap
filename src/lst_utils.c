/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:32 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 20:26:16 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

size_t	ft_lst_size(t_lst *head)
{
	size_t	elements_count;
	t_lst	*tempo;

	if (!head)
		return (0);
	elements_count = 0;
	tempo = head;
	while (tempo->next != head)
	{
		elements_count++;
		tempo = tempo->next;
	}
	elements_count++;
	return (elements_count);
}

void	ft_lstclear(t_lst *head)
{
	t_lst	*current;
	t_lst	*next;

	if (!head)
		return ;
	current = head;
	while (current->next != head)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
}

void	ft_lstadd_back(t_lst **head, t_lst *new)
{
	t_lst	*last;
	t_lst	*tempo;

	if (!head)
		return ;
	tempo = *head;
	if (!tempo)
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return ;
	}
	last = tempo->prev;
	last->next = new;
	new->prev = last;
	tempo->prev = new;
	new->next = tempo;
}

t_lst	*ft_lst_new(t_lst *head)
{
	head->next = head;
	head->prev = head;
	return (head);
}
