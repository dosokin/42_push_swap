/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onchain_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:49 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/23 19:03:36 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_swap(t_lst **head)
{
	t_lst	*z;
	t_lst	*a;
	t_lst	*b;
	t_lst	*c;

	if (!head || *head == (*head)->next)
		return ;
	a = (*head);
	z = a->prev;
	b = a->next;
	c = b->next;
	a->prev = b;
	a->next = c;
	z->next = b;
	b->prev = z;
	b->next = a;
	c->prev = a;
	*head = b;
}

void	insert(t_lst *a, t_lst *b)
{
	t_lst	*z;

	if (!a || !b)
		return ;
	z = b->prev;
	a->next = b;
	a->prev = z;
	z->next = a;
	b->prev = a;
}

void	action_push(t_lst **head_src, t_lst **head_dst)
{
	t_lst	*new_head_src;

	if (!head_src || !*head_src || !head_dst)
		return ;
	if ((*head_src) != (*head_src)->next)
		new_head_src = (*head_src)->next;
	else
		new_head_src = NULL;
	(*head_src)->prev->next = (*head_src)->next;
	(*head_src)->next->prev = (*head_src)->prev;
	if (!*head_dst)
		*head_dst = ft_lst_new(*head_src);
	else
		insert(*head_src, *head_dst);
	*head_dst = *head_src;
	*head_src = new_head_src;
}

void	action_rotate(t_lst **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->next;
}

void	action_reverse_rotate(t_lst **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->prev;
}
