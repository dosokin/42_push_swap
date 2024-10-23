/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:22:17 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:22:20 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_configuration(t_lst *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->value;
	b = stack_a->next->value;
	c = stack_a->prev->value;
	if (a < b && b < c)
		return (0);
	if (a > b && b > c)
		return (2);
	if (a > b && b < c)
	{
		if (a < c)
			return (1);
		return (4);
	}
	if (a < b && b > c)
	{
		if (a < c)
			return (5);
		return (3);
	}
	return (-1);
}

void	sort_three_elements(t_lst **stack_a)
{
	int	configuration;

	configuration = get_configuration(*stack_a);
	if (configuration == 1 || configuration == 2 || configuration == 5)
		sa(stack_a);
	if (configuration == 2 || configuration == 3)
		rra(stack_a);
	if (configuration == 4 || configuration == 5)
		ra(stack_a);
}
