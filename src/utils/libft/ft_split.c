/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:23:31 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 20:50:57 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

static void	*clean_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	get_parts_number(char *s, char c)
{
	size_t	i;
	size_t	parts_count;
	bool	content;

	if (!s)
		return (0);
	i = 0;
	content = false;
	parts_count = 0;
	while (s[i])
	{
		if (s[i] != c)
			content = true;
		if (s[i] == c && content)
		{
			parts_count++;
			content = false;
		}
		i++;
	}
	return (parts_count);
}

static char	*crop(char *s, size_t *start, char c)
{
	char	*result;
	size_t	i;
	size_t	end;

	if (!s)
		return (NULL);
	end = *start + 1;
	while (s[end] && s[end] != c)
		end++;
	result = malloc((end - *start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*start < end)
	{
		result[i] = s[*start];
		i++;
		(*start)++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char *s, char c)
{
	size_t	parts;
	char	**splitted;
	size_t	start;
	size_t	i;

	if (!s)
		return (NULL);
	parts = get_parts_number(s, c);
	splitted = malloc((parts + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			splitted[i] = crop(s, &start, c);
			if (!splitted[i++])
				return (clean_array((void **)splitted));
		}
		start++;
	}
	splitted[i] = NULL;
	return (splitted);
}
