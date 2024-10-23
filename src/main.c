/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:38 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/21 08:57:47 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	struct s_stacks	stacks;
	char			**prettified_args;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc < 2)
		return (1);
	argv++;
	if (check_for_empty_arg(argv))
		return (error_manager(SYNTAX_ERR));
	prettified_args = get_arguments(argc, argv);
	if (!prettified_args)
		return (error_manager(MEM_ERR));
	stacks.a = extract_elements(prettified_args);
	clear_tab(prettified_args);
	if (!stacks.a)
		return (error_manager(MEM_ERR));
	if (!is_sorted(stacks))
		sort_elements(stacks);
	ft_lstclear(stacks.a);
	ft_lstclear(stacks.b);
	return (EXIT_SUCCESS);
}
