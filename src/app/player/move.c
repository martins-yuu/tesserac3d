/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tforster@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:32:18 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/14 13:58:53 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/map/map.h"
#include "app/player/player.h"
#include "core/ctx/ctx.h"
#include "core/math/math.h"
#include "core/types/types.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define WALL_OFFSET 0.2f

static bool			will_collide(t_player *player, t_map *map,
						t_ivector2 position);
static t_vector2	get_wall_offset(t_player *player);

void	player_move(t_player *player, t_map *map, t_direction direction)
{
	int32_t		dir;
	t_vector2	wall_offset;
	t_ivector2	new_pos;

	dir = -direction_to_ivector2(direction).y;
	wall_offset = get_wall_offset(player);
	new_pos = (t_ivector2){
		.x = player->position.x + dir * wall_offset.x,
		.y = player->position.y + dir * wall_offset.y,
	};
	if (!will_collide(player, map, new_pos))
		player->position.x += dir * player->displacement.x * ctx()->delta_time
			* player->move_speed;
	if (!will_collide(player, map, new_pos))
		player->position.y += dir * player->displacement.y * ctx()->delta_time
			* player->move_speed;
}

void	player_strafe(t_player *player, t_map *map, t_direction direction)
{
	(void)map;
	player->position.x -= direction_to_ivector2(direction).x
		* player->displacement.y * ctx()->delta_time * player->strafe_speed;
	player->position.y -= -direction_to_ivector2(direction).x
		* player->displacement.x * ctx()->delta_time * player->strafe_speed;
}

void	player_yaw(t_player *player, t_map *map, t_direction direction)
{
	(void)map;
	player->direction_angle = normalize_angle(player->direction_angle
			- direction_to_ivector2(direction).x * ctx()->delta_time
			* player->yaw_speed);
	player->displacement.x = cosf(deg_to_rad(player->direction_angle));
	player->displacement.y = -sinf(deg_to_rad(player->direction_angle));
}

static bool	will_collide(t_player *player, t_map *map, t_ivector2 position)
{
	return (map_component_at(map,
			ivector2_add(ivector2_from_vector2(player->position),
				position)) == MAP_WALL);
}

static t_vector2	get_wall_offset(t_player *player)
{
	return ((t_vector2){
		.x = (player->displacement.x <= 0) * (-WALL_OFFSET)
			+ (player->displacement.x > 0) * WALL_OFFSET,
		.y = (player->displacement.y <= 0) * (-WALL_OFFSET)
			+ (player->displacement.y > 0) * WALL_OFFSET,
	});
}
