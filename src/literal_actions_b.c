/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal_actions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:18 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:21:20 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sb(t_lst **head_stack_b)
{
	write(1, "sb\n", 3);
	action_swap(head_stack_b);
}

void	pb(struct s_stacks *stacks)
{
	write(1, "pb\n", 3);
	action_push(&stacks->a, &stacks->b);
}

void	rb(t_lst **head_stack_b)
{
	write(1, "rb\n", 3);
	action_rotate(head_stack_b);
}

void	rrb(t_lst **head_stack_b)
{
	write(1, "rrb\n", 4);
	action_reverse_rotate(head_stack_b);
}
