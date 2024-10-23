/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:04 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:25:06 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static void	do_instruction(struct s_stacks *stacks,
		enum e_instruction instruction)
{
	if (instruction == PA)
		action_push(&stacks->b, &stacks->a);
	if (instruction == PB)
		action_push(&stacks->a, &stacks->b);
	if (instruction == SA || instruction == SS)
		action_swap(&stacks->a);
	if (instruction == SB || instruction == SS)
		action_swap(&stacks->b);
	if (instruction == RA || instruction == RR)
		action_rotate(&stacks->a);
	if (instruction == RB || instruction == RR)
		action_rotate(&stacks->b);
	if (instruction == RRA || instruction == RRR)
		action_reverse_rotate(&stacks->a);
	if (instruction == RRB || instruction == RRR)
		action_reverse_rotate(&stacks->b);
}

void	apply_instructions(struct s_stacks *stacks,
		t_lst_instructions *instructions)
{
	if (!instructions)
		return ;
	while (instructions)
	{
		do_instruction(stacks, instructions->instruction);
		instructions = instructions->next;
	}
}
