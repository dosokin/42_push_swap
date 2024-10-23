/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_instructions_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:22 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 19:22:27 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lst_add_back(t_lst_instructions **head, t_lst_instructions *new)
{
	t_lst_instructions	*tempo;

	if (!head)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tempo = *head;
	while (tempo->next)
		tempo = tempo->next;
	tempo->next = new;
}
