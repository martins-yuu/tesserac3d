/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:38:09 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 23:07:14 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/game/game.h"
#include "app/map/map.h"
#include "app/ray/ray.h"
#include "core/color/color.h"
#include "core/ctx/constants.h"
#include "core/draw/draw.h"
#include "core/math/math.h"
#include <math.h>
#include <stdint.h>
#include <sys/param.h>

static t_color	get_block_color(t_game *game, t_ivector2 position);

void	render_minimap(t_game *game)
{
	size_t		block_size;
	t_ivector2	pos;
	t_rectangle	rec;

	block_size = MIN(game->minimap->width / game->scene->map->width,
			game->minimap->height / game->scene->map->height);
	rec.size.x = block_size;
	rec.size.y = rec.size.x;
	pos.y = 0;
	while (pos.y < (int32_t)game->scene->map->height)
	{
		pos.x = 0;
		while (pos.x < (int32_t)game->scene->map->width)
		{
			rec.position.x = pos.x * block_size;
			rec.position.y = pos.y * block_size;
			draw_rectangle(game->minimap, rec, get_block_color(game, pos));
			pos.x++;
		}
		pos.y++;
	}
}

static t_color	get_block_color(t_game *game, t_ivector2 position)
{
	t_map_component	component;
	t_color			c;

	component = map_component_at(game->scene->map, position);
	if (component == MAP_OUT_OF_BOUNDS)
		return (color_opacity(color(COLOR_BLACK), 10 / 100.0f));
	else if (component == MAP_WALL)
		c = game->scene->floor_color;
	else
		c = game->scene->ceiling_color;
	if ((position.x + position.y) % 2 == 0)
		c = color_lerp(c, color(COLOR_GRAY), 10 / 100.0f);
	else
		c = color_lerp(c, color(COLOR_WHITE), 10 / 100.0f);
	if (component == MAP_WALL)
		c = color_lerp(c, color(COLOR_WHITE), 20 / 100.0f);
	else if (component == MAP_DOOR)
		c = color_lerp(c, color(COLOR_BLACK), 50 / 100.0f);
	else
		c = color_lerp(c, color(COLOR_BLACK), 20 / 100.0f);
	if (ivector2_eq(position, ivector2_from_vector2(game->player.position)))
		c = color_lerp(c, color(COLOR_WHITE), 80 / 100.0f);
	c = color_opacity(c, 0.5f);
	return (c);
}
