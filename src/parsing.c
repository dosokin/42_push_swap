/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:21:54 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 20:26:35 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>

char	**get_arguments(int argc, char **argv)
{
	char	*joined;
	char	**splitted;

	joined = ft_strjoin(argc, argv);
	if (!joined)
		return (NULL);
	splitted = ft_split(joined, ' ');
	free(joined);
	if (!splitted)
		return (NULL);
	return (splitted);
}

static bool	is_duplicate(int to_find, t_lst *head)
{
	t_lst	*tempo;

	if (!head)
		return (false);
	tempo = head;
	while (tempo->next != head)
	{
		if (to_find == tempo->value)
			return (true);
		tempo = tempo->next;
	}
	if (to_find == tempo->value)
		return (true);
	return (false);
}

static t_lst	*init_new_element(char *value)
{
	t_lst	*new_element;
	int		error;

	error = -1;
	new_element = malloc(sizeof(t_lst));
	if (!new_element)
		return (NULL);
	new_element->value = ft_safe_atoi(value, &error);
	if (error != -1)
	{
		free(new_element);
		return (NULL);
	}
	return (new_element);
}

t_lst	*extract_elements(char **elements)
{
	size_t	i;
	t_lst	*head;
	t_lst	*tempo;

	head = NULL;
	i = 0;
	while (elements[i])
	{
		tempo = init_new_element(elements[i]);
		if (!tempo || is_duplicate(tempo->value, head))
		{
			if (tempo)
				free(tempo);
			error_manager(DUPLICATED_ELEMENT);
			ft_lstclear(head);
			return (NULL);
		}
		ft_lstadd_back(&head, tempo);
		i++;
	}
	return (head);
}

bool	check_for_empty_arg(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				break ;
			j++;
		}
		if (!argv[i][j])
			return (true);
		i++;
	}
	return (false);
}
