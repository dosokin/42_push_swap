/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:59 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:22:01 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_score(struct s_stacks stacks, t_lst *target,
		enum e_path_type *move_type)
{
	size_t	best_score;
	size_t	target_moves[2];
	size_t	match_moves[2];
	t_lst	*match;

	best_score = MY_UINT_MAX;
	match = floor_matchmaking(stacks.b, target->value);
	set_moves_to_top_count(stacks.a, target, target_moves);
	set_moves_to_top_count(stacks.b, match, match_moves);
	*move_type = CONFLICT;
	if (target_moves[STANDARD] + match_moves[REVERSE] < best_score)
		best_score = target_moves[STANDARD] + match_moves[REVERSE];
	if (target_moves[REVERSE] + match_moves[STANDARD] < best_score)
		best_score = target_moves[REVERSE] + match_moves[STANDARD];
	if (get_max(target_moves[STANDARD], match_moves[STANDARD]) < best_score)
	{
		best_score = get_max(target_moves[STANDARD], match_moves[STANDARD]);
		*move_type = COMMON_ROTATE;
	}
	if (get_max(target_moves[REVERSE], match_moves[REVERSE]) < best_score)
	{
		best_score = get_max(target_moves[REVERSE], match_moves[REVERSE]);
		*move_type = COMMON_R_ROTATE;
	}
	return (best_score);
}