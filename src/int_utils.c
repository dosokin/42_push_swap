/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:20:59 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 10:21:02 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	get_difference(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

size_t	get_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
