/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:12:38 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 13:43:40 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/error.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "map.h"
#include "util/ansi_color.h"
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

t_map	*map_new(void)
{
	t_map	*map;

	map = error_expect(malloc(sizeof(t_map)), "malloc");
	*map = (t_map){
		.content = error_expect(ft_stnnew_empty(), "ft_stnnew_empty"),
	};
	return (map);
}

void	map_free(t_map *map)
{
	ft_stnfree(map->content);
	free(map);
}

t_map	*map_copy(const t_map *other)
{
	t_map	*map;

	map = map_new();
	map->width = other->width;
	map->height = other->height;
	map->start_position = other->start_position;
	map->start_orientation = other->start_orientation;
	map->normalized = other->normalized;
	map->content = error_expect(ft_stncpy_size(map->content, other->content,
				ft_stnlen(other->content)), "ft_stncpy_size");
	return (map);
}

void	map_print(const t_map *map)
{
	t_ivector2	pos;

	pos.y = 0;
	while (pos.y < (int32_t)map->height)
	{
		pos.x = 0;
		while (pos.x < (int32_t)map->width)
		{
			if (map_component_at(map, pos) == MAP_OUT_OF_BOUNDS)
				ft_putstr(ANSI_COLOR_MAGENTA);
			else if (map_component_at(map, pos) == MAP_WALL)
				ft_putstr(ANSI_COLOR_YELLOW);
			else
				ft_putstr(ANSI_COLOR_BLUE);
			ft_putchar(map_at(map, pos));
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
	ft_putstr(ANSI_COLOR_RESET);
	printf("width: %zu\nheight: %zu\n", map->width, map->height);
	printf("start_position: {x: %d, y: %d}\n", map->start_position.x,
		map->start_position.y);
	printf("start_orientation: %s\n",
		orientation_to_string(map->start_orientation));
}

void	map_highlight(const t_map *map, const t_ivector2 position)
{
	t_ivector2	pos;

	pos.y = 0;
	while (pos.y < (int32_t)map->height)
	{
		pos.x = 0;
		while (pos.x < (int32_t)map->width)
		{
			if (pos.x == position.x && pos.y == position.y)
				ft_putstr(ANSI_COLOR_RED);
			ft_putchar(map_at(map, pos));
			ft_putstr(ANSI_COLOR_RESET);
			pos.x++;
		}
		ft_putchar('\n');
		pos.y++;
	}
}
