/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:53 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/22 17:33:02 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

typedef enum e_instruction
{
	EOF,
	UNKNOWN,
	PA,
	PB,
	SS,
	SA,
	SB,
	RR,
	RA,
	RB,
	RRR,
	RRA,
	RRB
}								t_instruction;

typedef struct s_lst_instructions
{
	t_instruction				instruction;
	struct s_lst_instructions	*next;
}								t_lst_instructions;

t_lst_instructions				*get_instructions(void);
void							apply_instructions(struct s_stacks *stacks,
									t_lst_instructions *instructions);

int								error_manager(enum e_error_type type);

void							clear_instructions(t_lst_instructions **head);
void							clear_buffer(char *ptr);

int								clean_exit(struct s_stacks stacks,
									char **prettified_args,
									t_lst_instructions *instructions,
									int error);

void							lst_add_back(t_lst_instructions **head,
									t_lst_instructions *new);

#endif
