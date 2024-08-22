/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:03:06 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/05 00:40:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/map/map.h"
#include "common/file.h"
#include "ft_arraylist.h"
#include "scene.h"
#include "scene_internal.h"
#include <stddef.h>

t_scene_result	scene_parse(const char *filename)
{
	t_scene	*scene;
	t_array	*lines;

	if (!file_check_extension(filename, SCENE_FILE_EXTENSION))
		return ((t_scene_result){NULL, SCENE_INVALID_EXTENSION});
	lines = file_read_lines(filename);
	if (!lines)
		return ((t_scene_result){NULL, SCENE_INVALID_FILE});
	scene = scene_new();
	scene_build(scene, lines);
	if (scene->map->error)
		return (file_free_lines(lines), scene_free(scene),
			(t_scene_result){NULL, SCENE_INVALID_MAP});
	if (!scene_is_required_set(scene))
		return (file_free_lines(lines), scene_free(scene),
			(t_scene_result){NULL, SCENE_MISSING_ELEMENT});
	if (!ft_arrisempty(scene->errors))
		return (file_free_lines(lines), scene_free(scene),
			(t_scene_result){NULL, SCENE_INVALID_ELEMENT});
	if (!map_validate(scene->map))
		return (file_free_lines(lines), scene_free(scene),
			(t_scene_result){NULL, SCENE_INVALID_MAP});
	return (file_free_lines(lines), (t_scene_result){scene, SCENE_SUCCESS});
}
