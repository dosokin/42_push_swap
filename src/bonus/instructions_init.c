/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:15 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/22 17:30:27 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100001

static t_instruction	get_instruction(char *buffer)
{
	if (!ft_strcmp(buffer, "\n"))
		return (EOF);
	if (!ft_strcmp(buffer, "pa\n"))
		return (PA);
	if (!ft_strcmp(buffer, "pb\n"))
		return (PB);
	if (!ft_strcmp(buffer, "ss\n"))
		return (SS);
	if (!ft_strcmp(buffer, "sa\n"))
		return (SA);
	if (!ft_strcmp(buffer, "sb\n"))
		return (SB);
	if (!ft_strcmp(buffer, "rr\n"))
		return (RR);
	if (!ft_strcmp(buffer, "ra\n"))
		return (RA);
	if (!ft_strcmp(buffer, "rb\n"))
		return (RB);
	if (!ft_strcmp(buffer, "rrr\n"))
		return (RRR);
	if (!ft_strcmp(buffer, "rra\n"))
		return (RRA);
	if (!ft_strcmp(buffer, "rrb\n"))
		return (RRB);
	return (UNKNOWN);
}

static t_lst_instructions	*init_new_instruction(t_instruction instruction)
{
	t_lst_instructions	*new_instruction;

	new_instruction = malloc(sizeof(t_lst_instructions));
	if (!new_instruction)
		return (NULL);
	new_instruction->instruction = instruction;
	new_instruction->next = NULL;
	return (new_instruction);
}

int	treat_instruction(t_lst_instructions **instructions_lst,
		enum e_instruction instruction)
{
	static t_lst_instructions	*new_instruction_node;

	new_instruction_node = init_new_instruction(instruction);
	if (!new_instruction_node)
	{
		error_manager(MEM_ERR);
		clear_instructions(instructions_lst);
		return (1);
	}
	lst_add_back(instructions_lst, new_instruction_node);
	return (0);
}

t_lst_instructions	*get_instructions(void)
{
	char				*s;
	t_lst_instructions	*instructions_lst;
	enum e_instruction	instruction;

	instructions_lst = NULL;
	s = get_next_line(0);
	while (s)
	{
		instruction = get_instruction(s);
		free(s);
		if (instruction == UNKNOWN)
		{
			error_manager(UNKNOWN_INSTRUCTION);
			clear_instructions(&instructions_lst);
			break ;
		}
		else if (instruction == EOF)
			break ;
		if (treat_instruction(&instructions_lst, instruction) == ERROR)
			break ;
		s = get_next_line(0);
	}
	get_next_line(-999);
	return (instructions_lst);
}
