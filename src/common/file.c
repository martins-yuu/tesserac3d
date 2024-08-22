/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:44:29 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 17:30:00 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/error.h"
#include "ft_arraylist.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

t_array	*file_read_lines(const char *filename)
{
	t_array		*lines;
	int			fd;
	t_string	line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = error_expect(ft_arrnew(sizeof(t_string)), "ft_arrnew");
	while (true)
	{
		line = get_next_line(fd);
		if (errno != 0)
			return (close(fd), ft_arrfree(lines), NULL);
		if (!line)
			break ;
		if (!ft_arrappend(lines, &line))
			error_panic("ft_arrappend");
	}
	if (close(fd) == -1)
		error_panic("close");
	return (lines);
}

void	file_free_lines(t_array *lines)
{
	size_t	i;

	i = 0;
	while (i < ft_arrsize(lines))
	{
		ft_stnfree(*(t_string *)ft_arrat(lines, i));
		i++;
	}
	ft_arrfree(lines);
}

bool	file_check_extension(const char *filename, const char *extension)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (false);
	return (ft_strncmp(dot + 1, extension, ft_strlen(extension) + 1) == 0);
}
