/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:54:24 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 21:28:34 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/map/map.h"
#include "common/error.h"
#include "core/color/color.h"
#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_string.h"
#include "scene.h"
#include "scene_internal.h"
#include <stddef.h>

static void	build_elements(t_scene *scene);
static void	build_color(t_scene *scene, const t_hashmap_iterator *entry);
static void	build_texture(t_scene *scene, const t_hashmap_iterator *entry);

void	scene_build(t_scene *scene, t_array *lines)
{
	size_t		i;
	t_string	*str;

	i = 0;
	while (i < ft_arrsize(lines))
	{
		str = ft_arrat(lines, i);
		ft_stnrstrip_space(*str);
		if (!ft_stnisempty(*str) && !scene_set_element(scene, *str))
			break ;
		i++;
	}
	while (i < ft_arrsize(lines))
	{
		str = ft_arrat(lines, i);
		ft_stnrstrip_space(*str);
		if (!ft_stnisempty(*str))
			map_add_row(scene->map, *str);
		else
			map_add_row(scene->map, map_component_to_string(MAP_OUT_OF_BOUNDS));
		i++;
	}
	map_normalize(scene->map);
	build_elements(scene);
}

static void	build_elements(t_scene *scene)
{
	t_hashmap_iterator	it;
	t_scene_element		type;

	it = ft_hshbegin(scene->config);
	while (ft_hshnext(&it))
	{
		type = scene_element_from_string(it.key);
		if ((1 << type) & (1 << SCENE_FLOOR_COLOR | 1 << SCENE_CEILING_COLOR))
			build_color(scene, &it);
		else
			build_texture(scene, &it);
	}
}

static void	build_color(t_scene *scene, const t_hashmap_iterator *entry)
{
	t_color_result	res;

	res = color_parse_rgb(entry->value);
	if (res.error)
		return (scene_add_error(scene, SCENE_INVALID_COLOR));
	if (scene_element_from_string(entry->key) == SCENE_FLOOR_COLOR)
		scene->floor_color = res.color;
	else if (scene_element_from_string(entry->key) == SCENE_CEILING_COLOR)
		scene->ceiling_color = res.color;
}

static void	build_texture(t_scene *scene, const t_hashmap_iterator *entry)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(entry->value);
	if (!texture)
		return (scene_add_error(scene, SCENE_INVALID_TEXTURE));
	if (!ft_hshset(scene->textures, entry->key, texture))
		error_panic("ft_hshset");
}
