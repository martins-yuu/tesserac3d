/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 05:08:30 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 02:21:44 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/error.h"
#include "core/math/math.h"
#include "core/types/types.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "map.h"
#include <stddef.h>
#include <sys/param.h>

void	map_add_row(t_map *map, const char *row)
{
	if (ft_strchr(row, map_component_to_char(MAP_OUT_OF_BOUNDS)))
		map->error = true;
	map->width = MAX(map->width, ft_strlen(row));
	map->height++;
	map->content = error_expect(ft_stncat(map->content, row), "ft_stncat");
	map->content = error_expect(ft_stncat(map->content, "\n"), "ft_stncat");
	map->normalized = false;
}

void	map_normalize(t_map *map)
{
	t_string	*rows;
	size_t		i;
	size_t		j;

	rows = error_expect(ft_split(map->content, '\n'), "ft_split");
	ft_stnclear(map->content);
	i = 0;
	while (rows[i] != NULL)
	{
		j = 0;
		while (rows[i][j] != '\0')
		{
			if (ft_isspace(rows[i][j]))
				rows[i][j] = map_component_to_char(MAP_OUT_OF_BOUNDS);
			j++;
		}
		rows[i] = error_expect(ft_stnrpad(rows[i], map->width,
					map_component_to_char(MAP_OUT_OF_BOUNDS)), "ft_stnrpad");
		map->content = error_expect(ft_stncat(map->content, rows[i]),
				"ft_stncat");
		i++;
	}
	ft_freesplit(rows);
	map->normalized = true;
}

void	map_fill(t_map *map, t_ivector2 position)
{
	t_direction	dir;

	if (map_is_out_of_bounds(map, position))
		return ((void)(map->error = true));
	if (map_at(map, position) == map_component_to_char(MAP_WALL))
		return ;
	map_set(map, position, map_component_to_char(MAP_WALL));
	dir = DIRECTION_BEGIN;
	while (dir < DIRECTION_END)
	{
		map_fill(map, ivector2_add(position, direction_to_ivector2(dir)));
		dir++;
	}
}
