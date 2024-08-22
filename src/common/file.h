/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:16:56 by yuuko             #+#    #+#             */
/*   Updated: 2024/08/21 22:03:00 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "ft_arraylist.h"
# include <stdbool.h>

t_array	*file_read_lines(const char *filename);
void	file_free_lines(t_array *lines);
bool	file_check_extension(const char *filename, const char *extension);

#endif
