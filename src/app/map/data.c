/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:47:50 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 02:21:35 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/math/math.h"
#include "map.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t	map_size(const t_map *map)
{
	return (map->width * map->height);
}

char	map_at(const t_map *map, t_ivector2 position)
{
	assert(map->normalized);
	if (position.x < 0 || position.x >= (int32_t)map->width)
		return (MAP_OUT_OF_BOUNDS);
	if (position.y < 0 || position.y >= (int32_t)map->height)
		return (MAP_OUT_OF_BOUNDS);
	return (map->content[position.y * map->width + position.x]);
}

void	map_set(t_map *map, t_ivector2 position, char value)
{
	assert(map->normalized);
	assert(position.x >= 0 && position.x < (int32_t)map->width);
	assert(position.y >= 0 && position.y < (int32_t)map->height);
	map->content[position.y * map->width + position.x] = value;
}

bool	map_is_out_of_bounds(const t_map *map, t_ivector2 position)
{
	if (position.x < 0 || position.x >= (int32_t)map->width)
		return (true);
	if (position.y < 0 || position.y >= (int32_t)map->height)
		return (true);
	if (map_component_at(map, position) == MAP_OUT_OF_BOUNDS)
		return (true);
	return (false);
}
