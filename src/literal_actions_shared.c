/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal_actions_shared.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:26 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:21:28 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(struct s_stacks *stacks)
{
	write(1, "ss\n", 3);
	action_swap(&stacks->a);
	action_swap(&stacks->b);
}

void	rr(struct s_stacks *stacks)
{
	write(1, "rr\n", 3);
	action_rotate(&stacks->a);
	action_rotate(&stacks->b);
}

void	rrr(struct s_stacks *stacks)
{
	write(1, "rrr\n", 4);
	action_reverse_rotate(&stacks->a);
	action_reverse_rotate(&stacks->b);
}
