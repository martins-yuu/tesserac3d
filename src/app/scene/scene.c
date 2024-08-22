/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:02:47 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/12 17:23:42 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/map/map.h"
#include "common/error.h"
#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_string.h"
#include "scene.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_scene	*scene_new(void)
{
	t_scene	*scene;

	scene = error_expect(malloc(sizeof(t_scene)), "malloc");
	*scene = (t_scene){
		.config = error_expect(ft_hshnew(NULL), "ft_hshnew"),
		.textures = error_expect(ft_hshnew(NULL), "ft_hshnew"),
		.map = map_new(),
		.errors = error_expect(ft_arrnew(sizeof(t_scene_error)), "ft_arrnew"),
	};
	return (scene);
}

void	scene_free(t_scene *scene)
{
	t_hashmap_iterator	it;

	if (!scene)
		return ;
	it = ft_hshbegin(scene->config);
	while (ft_hshnext(&it))
		ft_stnfree(it.value);
	ft_hshfree(scene->config);
	it = ft_hshbegin(scene->textures);
	while (ft_hshnext(&it))
		mlx_delete_texture(it.value);
	ft_hshfree(scene->textures);
	map_free(scene->map);
	ft_arrfree(scene->errors);
	free(scene);
}

void	scene_print(const t_scene *scene)
{
	t_hashmap_iterator	it;

	map_print(scene->map);
	it = ft_hshbegin(scene->config);
	while (ft_hshnext(&it))
		printf("%s: %s\n", it.key, (char *)it.value);
	printf("floor_color: #%08X\n", scene->floor_color.value);
	printf("ceiling_color: #%08X\n", scene->ceiling_color.value);
}
