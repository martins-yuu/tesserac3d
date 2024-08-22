/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:04:34 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 21:27:54 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/error.h"
#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_string.h"
#include "scene.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool	scene_set_element(t_scene *scene, const char *str)
{
	t_array			*data;
	t_scene_element	type;
	t_string		value;

	data = error_expect(ft_stnsplit_space(str), "ft_stnsplit_space");
	if (ft_arrsize(data) < 2)
		return (ft_stnfreesplit(data), false);
	type = scene_element_from_string(*(t_string *)ft_arrat(data, 0));
	if (type == SCENE_ELEMENT_ILLEGAL)
		return (ft_stnfreesplit(data), false);
	if (ft_hshget(scene->config, scene_element_to_string(type)))
	{
		printf("Duplicate element: %s\n", scene_element_to_string(type));
		return (ft_stnfreesplit(data), false);
	}
	value = error_expect(ft_stnjoin_range(data, " ", 1, -1), "ft_stnjoinrange");
	if (!ft_hshset(scene->config, scene_element_to_string(type), value))
		return (ft_stnfreesplit(data), false);
	return (ft_stnfreesplit(data), true);
}

const char	*scene_element_to_string(t_scene_element element)
{
	assert(element >= SCENE_ELEMENT_ILLEGAL && element < SCENE_ELEMENT_END);
	return ((const char *[]){
		[SCENE_ELEMENT_ILLEGAL] = NULL,
		[SCENE_NORTH_TEXTURE] = "NO",
		[SCENE_SOUTH_TEXTURE] = "SO",
		[SCENE_WEST_TEXTURE] = "WE",
		[SCENE_EAST_TEXTURE] = "EA",
		[SCENE_FLOOR_COLOR] = "F",
		[SCENE_CEILING_COLOR] = "C",
		[SCENE_FLOOR_TEXTURE] = "FL",
		[SCENE_CEILING_TEXTURE] = "CE",
		[SCENE_DOOR_TEXTURE] = "DO",
	}[element]);
}

t_scene_element	scene_element_from_string(const char *name)
{
	size_t		i;
	const char	*identifier;

	i = SCENE_ELEMENT_BEGIN;
	while (i < SCENE_ELEMENT_END)
	{
		identifier = scene_element_to_string(i);
		if (ft_strncmp(name, identifier, ft_strlen(identifier) + 1) == 0)
			return ((t_scene_element)i);
		i++;
	}
	return (SCENE_ELEMENT_ILLEGAL);
}

bool	scene_is_required_set(const t_scene *scene)
{
	size_t	i;

	i = SCENE_ELEMENT_BEGIN;
	while (i <= SCENE_ELEMENT_REQUIRED)
	{
		if (!ft_hshget(scene->config, scene_element_to_string(i)))
		{
			printf("Missing element: %s\n", scene_element_to_string(i));
			return (false);
		}
		i++;
	}
	return (true);
}
