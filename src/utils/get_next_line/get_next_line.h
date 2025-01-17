/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:59:39 by dosokin           #+#    #+#             */
/*   Updated: 2024/08/03 18:23:21 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin_special(char *a, char *b);
char	*get_next_line(int fd);
char	*ft_calloc(unsigned int amount, unsigned int size);
int		find_new_line(const char *s);

enum	e_exit_type
{
	EOF,
	ERR
};

#endif
