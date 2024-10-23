/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:24:57 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:24:59 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"
#include <stdlib.h>

int	clean_exit(struct s_stacks stacks, char **prettified_args,
		t_lst_instructions *instructions, int error)
{
	if (stacks.a)
		ft_lstclear(stacks.a);
	if (stacks.b)
		ft_lstclear(stacks.b);
	if (prettified_args && *prettified_args)
		clear_tab(prettified_args);
	if (instructions)
		clear_instructions(&instructions);
	if (error)
	{
		error_manager(error);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
