/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:28 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/22 17:23:04 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static bool	is_sorted(struct s_stacks stacks)
{
	t_lst	*tempo;
	int		prev;

	if (!stacks.a || stacks.b)
		return (false);
	tempo = stacks.a;
	prev = tempo->value;
	while (tempo->next != stacks.a)
	{
		if (tempo->value < prev)
			return (false);
		prev = tempo->value;
		tempo = tempo->next;
	}
	if (tempo->value < prev)
		return (false);
	return (true);
}

static void	display_result(struct s_stacks stacks)
{
	if (is_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	struct s_stacks		stacks;
	char				**prettified_args;
	t_lst_instructions	*instructions;

	stacks.a = NULL;
	stacks.b = NULL;
	instructions = NULL;
	if (argc < 2)
		return (1);
	argv++;
	if (check_for_empty_arg(argv))
		return (error_manager(SYNTAX_ERR));
	prettified_args = get_arguments(argc, argv);
	if (!prettified_args)
		return (error_manager(MEM_ERR));
	stacks.a = extract_elements(prettified_args);
	if (!stacks.a)
		return (clean_exit(stacks, prettified_args, instructions, MEM_ERR));
	instructions = get_instructions();
	if (instructions)
	{
		apply_instructions(&stacks, instructions);
		display_result(stacks);
	}
	return (clean_exit(stacks, prettified_args, instructions, false));
}
