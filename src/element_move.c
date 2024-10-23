/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:20:44 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/23 20:23:48 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_element_to_top(t_lst **stack, t_lst *target, t_stack stack_type)
{
	size_t	position;

	position = get_position(*stack, target);
	if (position <= ft_lst_size(*stack) / 2)
	{
		while (*stack != target)
		{
			if (stack_type == STACK_A)
				ra(stack);
			else if (stack_type == STACK_B)
				rb(stack);
		}
	}
	else
	{
		while (*stack != target)
		{
			if (stack_type == STACK_A)
				rra(stack);
			else if (stack_type == STACK_B)
				rrb(stack);
		}
	}
}

void	do_move(struct s_stacks *stacks, t_move best_move)
{
	if (best_move.type == COMMON_ROTATE)
		while (stacks->a != best_move.target && stacks->b != best_move.match)
			rr(stacks);
	else if (best_move.type == COMMON_R_ROTATE)
		while (stacks->a != best_move.target && stacks->b != best_move.match)
			rrr(stacks);
	move_element_to_top(&stacks->a, best_move.target, STACK_A);
	move_element_to_top(&stacks->b, best_move.match, STACK_B);
	pb(stacks);
}

t_move	create_move(struct s_stacks stacks, t_lst *to_move)
{
	t_move				move;
	enum e_path_type	move_type;

	move.target = to_move;
	move.match = find_nearest_low(stacks.b, to_move->value);
	move_type = get_best_path(stacks, to_move, move.match);
	move.type = move_type;
	return (move);
}
