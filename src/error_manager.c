/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:20:51 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/22 17:32:41 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <unistd.h>

int	error_manager(enum e_error_type type)
{
	static bool	broadcasted = false;
	const char	*errors[6] = {"", "issue allocating memory", "int overflow",
		"duplicated element", "syntax error", "unknown command"};

	if (type == IS_ERROR)
	{
		if (broadcasted)
			return (1);
		return (0);
	}
	if (broadcasted || type > 5)
		return (1);
	write(2, "Error\n", 6);
	write(2, errors[type], ft_strlen(errors[type]));
	write(2, "\n", 1);
	broadcasted = true;
	return (1);
}
