/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:22:09 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 19:22:44 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	init_stack_b(struct s_stacks *stacks)
{
	size_t	i;
	size_t	stack_size_a;

	stack_size_a = ft_lst_size(stacks->a);
	i = 1;
	while (i < 3 && stack_size_a - i >= 3)
	{
		pb(stacks);
		i++;
	}
}

static void	recave_a(struct s_stacks *stacks)
{
	t_lst	*ceil;

	while (ft_lst_size(stacks->b))
	{
		ceil = ceil_matchmaking(stacks->a, stacks->b->value);
		move_element_to_top(&stacks->a, ceil, STACK_A);
		pa(stacks);
	}
}

t_lst	*get_best_scorer(struct s_stacks stacks)
{
	t_lst				*tempo;
	t_lst				*best_scorer;
	size_t				score;
	enum e_path_type	move_type;

	score = MY_UINT_MAX;
	tempo = stacks.a;
	while (tempo->next != stacks.a)
	{
		if (get_score(stacks, tempo, &move_type) < score)
		{
			best_scorer = tempo;
			score = get_score(stacks, tempo, &move_type);
		}
		tempo = tempo->next;
	}
	if (get_score(stacks, tempo, &move_type) < score)
		best_scorer = tempo;
	return (best_scorer);
}

static void	empty_a(struct s_stacks *stacks)
{
	t_lst	*best_scorer;
	t_move	best_move;

	best_move.match = NULL;
	best_move.target = NULL;
	best_move.type = CONFLICT;
	while (ft_lst_size(stacks->a) > 3)
	{
		best_scorer = get_best_scorer(*stacks);
		best_move = create_move(*stacks, best_scorer);
		do_move(stacks, best_move);
	}
}

void	sort_elements(struct s_stacks stacks)
{
	if (ft_lst_size(stacks.a) >= 3)
	{
		init_stack_b(&stacks);
		empty_a(&stacks);
		sort_three_elements(&stacks.a);
		recave_a(&stacks);
	}
	move_element_to_top(&stacks.a, find_lowest(stacks.a), STACK_A);
}
