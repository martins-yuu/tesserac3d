/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:18:26 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 02:28:51 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/math/math.h"
#include "map.h"
#include <assert.h>

t_map_component	map_component_at(const t_map *map, t_ivector2 position)
{
	return (map_component_from_char(map_at(map, position)));
}

const char	*map_component_to_string(t_map_component component)
{
	assert(component >= MAP_COMPONENT_ILLEGAL && component < MAP_COMPONENT_END);
	return ((const char *[]){
		[MAP_COMPONENT_ILLEGAL] = NULL,
		[MAP_EMPTY] = "0",
		[MAP_WALL] = "1",
		[MAP_DOOR] = "D",
		[MAP_OUT_OF_BOUNDS] = "*",
	}[component]);
}

char	map_component_to_char(t_map_component component)
{
	assert(component != MAP_COMPONENT_ILLEGAL);
	return (*map_component_to_string(component));
}

t_map_component	map_component_from_string(const char *name)
{
	size_t		i;
	const char	*identifier;

	i = MAP_COMPONENT_BEGIN;
	while (i < MAP_COMPONENT_END)
	{
		identifier = map_component_to_string(i);
		if (ft_strncmp(name, identifier, ft_strlen(identifier) + 1) == 0)
			return ((t_map_component)i);
		i++;
	}
	return (MAP_COMPONENT_ILLEGAL);
}

t_map_component	map_component_from_char(char c)
{
	const char	name[] = {c, '\0'};

	return (map_component_from_string(name));
}
