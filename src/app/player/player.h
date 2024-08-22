/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:04:48 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 23:50:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "app/map/map.h"
# include "app/scene/scene.h"
# include "core/math/math.h"
# include "core/types/types.h"
# include <math.h>
# include <stdbool.h>

# define PLAYER_FOV 60.0f
# define PLAYER_HEIGHT 2.0f
# define PLAYER_PITCH 0.0f

# define PLAYER_MOVE_SPEED 4.0f
# define PLAYER_STRAFE_SPEED 4.0f
# define PLAYER_YAW_SPEED 150.0f

typedef struct s_player
{
	t_vector2	position;
	t_vector2	displacement;
	float_t		direction_angle;
	float_t		fov;
	float_t		height;
	float_t		pitch;
	float_t		move_speed;
	float_t		strafe_speed;
	float_t		yaw_speed;
	bool		is_jumping;
	bool		is_crouching;
}				t_player;

void			player_init(t_player *player, t_scene *scene);
void			player_move(t_player *player, t_map *map,
					t_direction direction);
void			player_strafe(t_player *player, t_map *map,
					t_direction direction);
void			player_yaw(t_player *player, t_map *map, t_direction direction);

#endif
