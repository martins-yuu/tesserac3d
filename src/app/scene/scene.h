/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:28:52 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 21:27:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "app/map/map.h"
# include "core/color/color.h"
# include "ft_arraylist.h"
# include "ft_hashmap.h"
# include <stdbool.h>

# define SCENE_FILE_EXTENSION "cub"

typedef struct s_scene
{
	t_hashmap		*config;
	t_hashmap		*textures;
	t_color			floor_color;
	t_color			ceiling_color;
	t_map			*map;
	t_array			*errors;
}					t_scene;

typedef enum e_scene_element
{
	SCENE_ELEMENT_ILLEGAL = 0,
	SCENE_NORTH_TEXTURE,
	SCENE_SOUTH_TEXTURE,
	SCENE_WEST_TEXTURE,
	SCENE_EAST_TEXTURE,
	SCENE_FLOOR_COLOR,
	SCENE_CEILING_COLOR,
	SCENE_FLOOR_TEXTURE,
	SCENE_CEILING_TEXTURE,
	SCENE_DOOR_TEXTURE,
	SCENE_ELEMENT_END,
	SCENE_ELEMENT_BEGIN = SCENE_ELEMENT_ILLEGAL + 1,
	SCENE_ELEMENT_COUNT = SCENE_ELEMENT_END - SCENE_ELEMENT_BEGIN,
	SCENE_ELEMENT_REQUIRED = SCENE_CEILING_COLOR,
}					t_scene_element;

typedef enum e_scene_error
{
	SCENE_SUCCESS = 0,
	SCENE_INVALID_EXTENSION,
	SCENE_INVALID_FILE,
	SCENE_INVALID_ELEMENT,
	SCENE_MISSING_ELEMENT,
	SCENE_INVALID_COLOR,
	SCENE_INVALID_TEXTURE,
	SCENE_INVALID_MAP,
}					t_scene_error;

typedef struct s_scene_result
{
	t_scene			*scene;
	t_scene_error	error;
}					t_scene_result;

t_scene				*scene_new(void);
void				scene_free(t_scene *scene);
void				scene_print(const t_scene *scene);
bool				scene_set_element(t_scene *scene, const char *str);
const char			*scene_element_to_string(t_scene_element element);
t_scene_element		scene_element_from_string(const char *name);
t_scene_result		scene_parse(const char *filename);
const char			*scene_error_to_string(t_scene_error error);

#endif
