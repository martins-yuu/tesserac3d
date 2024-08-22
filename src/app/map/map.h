/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:25:56 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/10 18:36:07 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "core/math/math.h"
# include "core/types/types.h"
# include "ft_string.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_map
{
	size_t			width;
	size_t			height;
	t_ivector2		start_position;
	t_orientation	start_orientation;
	t_string		content;
	bool			normalized;
	bool			error;
}					t_map;

typedef enum e_map_component
{
	MAP_COMPONENT_ILLEGAL = 0,
	MAP_EMPTY,
	MAP_WALL,
	MAP_DOOR,
	MAP_OUT_OF_BOUNDS,
	MAP_COMPONENT_END,
	MAP_COMPONENT_BEGIN = MAP_COMPONENT_ILLEGAL + 1,
	MAP_COMPONENT_COUNT = MAP_COMPONENT_END - MAP_COMPONENT_BEGIN
}					t_map_component;

t_map				*map_new(void);
void				map_free(t_map *map);
t_map				*map_copy(const t_map *other);
size_t				map_size(const t_map *map);
char				map_at(const t_map *map, t_ivector2 position);
void				map_set(t_map *map, t_ivector2 position, char value);
bool				map_is_out_of_bounds(const t_map *map, t_ivector2 position);
void				map_add_row(t_map *map, const char *row);
void				map_normalize(t_map *map);
void				map_fill(t_map *map, t_ivector2 position);
t_map_component		map_component_at(const t_map *map, t_ivector2 position);
const char			*map_component_to_string(t_map_component component);
char				map_component_to_char(t_map_component component);
t_map_component		map_component_from_string(const char *name);
t_map_component		map_component_from_char(char c);
bool				map_validate(t_map *map);
void				map_print(const t_map *map);
void				map_highlight(const t_map *map, const t_ivector2 position);

#endif
