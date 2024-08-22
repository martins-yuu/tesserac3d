/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:04:58 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 20:26:07 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/scene/scene.h"
#include "core/types/types.h"
#include "player.h"
#include <math.h>
#include <stdbool.h>

void	player_init(t_player *player, t_scene *scene)
{
	*player = (t_player){
		.position.x = scene->map->start_position.x + 0.5f,
		.position.y = scene->map->start_position.y + 0.5f,
		.direction_angle = orientation_to_float(scene->map->start_orientation),
		.fov = PLAYER_FOV,
		.height = PLAYER_HEIGHT,
		.pitch = PLAYER_PITCH,
		.move_speed = PLAYER_MOVE_SPEED,
		.strafe_speed = PLAYER_STRAFE_SPEED,
		.yaw_speed = PLAYER_YAW_SPEED,
		.is_jumping = false,
		.is_crouching = false,
	};
	player->displacement.x = cosf(deg_to_rad(player->direction_angle));
	player->displacement.y = -sinf(deg_to_rad(player->direction_angle));
}
