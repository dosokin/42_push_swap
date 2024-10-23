/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:24:52 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 19:22:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdlib.h>

void	clear_buffer(char *ptr)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(ptr);
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}

void	clear_instructions(t_lst_instructions **head)
{
	t_lst_instructions	*prev;
	t_lst_instructions	*current;

	if (!head || !*head)
		return ;
	current = *head;
	while (current->next)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	free(current);
	*head = NULL;
}
