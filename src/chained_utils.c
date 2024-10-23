/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:20:29 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:20:31 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_chain(t_lst *head)
{
	t_lst	*tempo;

	if (!head)
		return ;
	tempo = head;
	while (tempo->next != head)
	{
		printf("%d\n", tempo->value);
		tempo = tempo->next;
	}
	printf("%d\n", tempo->value);
}
