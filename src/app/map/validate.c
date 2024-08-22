/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 05:17:24 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 14:56:22 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/math/math.h"
#include "core/types/types.h"
#include "map.h"
#include <math.h>
#include <stddef.h>

static bool	validate_components(t_map *map);
static bool	validate_bounds(const t_map *map);

bool	map_validate(t_map *map)
{
	if (!validate_components(map))
		return (false);
	map_set(map, map->start_position, map_component_to_char(MAP_EMPTY));
	if (!validate_bounds(map))
		return (false);
	return (true);
}

static bool	validate_components(t_map *map)
{
	t_orientation	start;
	size_t			i;
	t_ivector2		pos;

	start = ORIENTATION_ILLEGAL;
	i = 0;
	while (i < map_size(map))
	{
		pos = (t_ivector2){.x = i % map->width, .y = (float_t)i / map->width};
		if (!map_component_from_char(map->content[i]))
		{
			if (start)
				return (map_highlight(map, pos), false);
			start = orientation_from_char(map->content[i]);
			if (!start)
				return (map_highlight(map, pos), false);
			map->start_position = pos;
		}
		i++;
	}
	if (!start)
		return (map_highlight(map, pos), false);
	map->start_orientation = start;
	return (true);
}

static bool	validate_bounds(const t_map *map)
{
	t_map		*copy;
	size_t		i;
	t_ivector2	pos;

	copy = map_copy(map);
	i = 0;
	while (i < map_size(map))
	{
		pos = (t_ivector2){.x = i % map->width, .y = (float_t)i / map->width};
		if (map_component_at(copy, pos) != MAP_OUT_OF_BOUNDS
			&& map_component_at(map, pos) != MAP_WALL)
		{
			map_fill(copy, pos);
			if (copy->error)
				return (map_free(copy), map_highlight(map, pos), false);
		}
		i++;
	}
	return (map_free(copy), true);
}
