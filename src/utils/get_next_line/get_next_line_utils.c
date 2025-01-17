/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:59:56 by dosokin           #+#    #+#             */
/*   Updated: 2024/08/03 18:22:13 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		++i;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin_special(char *a, char *b)
{
	int		i;
	int		j;
	char	*joined;

	if (!a || !b)
		return (NULL);
	joined = malloc((ft_strlen(a) + ft_strlen(b) + 1) * sizeof(char));
	if (joined)
	{
		i = 0;
		j = 0;
		while (a[i])
			joined[j++] = a[i++];
		i = 0;
		while (b[i])
			joined[j++] = b[i++];
		joined[j] = 0;
	}
	free(a);
	free(b);
	return (joined);
}

char	*ft_calloc(unsigned int amount, unsigned int size)
{
	char			*s;
	unsigned int	i;

	i = 0;
	if (amount * size <= 0)
		return (NULL);
	s = malloc(amount * size);
	if (!s)
		return (NULL);
	while (i < amount)
	{
		s[i] = 0;
		++i;
	}
	return (s);
}

int	find_new_line(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}
