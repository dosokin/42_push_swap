/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal_actions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:11 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:21:12 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_lst **head_stack_a)
{
	write(1, "sa\n", 3);
	action_swap(head_stack_a);
}

void	pa(struct s_stacks *stacks)
{
	write(1, "pa\n", 3);
	action_push(&stacks->b, &stacks->a);
}

void	ra(t_lst **head_stack_a)
{
	write(1, "ra\n", 3);
	action_rotate(head_stack_a);
}

void	rra(t_lst **head_stack_a)
{
	write(1, "rra\n", 4);
	action_reverse_rotate(head_stack_a);
}
