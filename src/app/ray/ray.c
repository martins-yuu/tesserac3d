/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:51:34 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 21:32:55 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/game/game.h"
#include "app/map/map.h"
#include "core/math/math.h"
#include "ft_hashmap.h"
#include "ray.h"
#include <math.h>
#include <stdint.h>

#define LOOKING_LEFT 0.001f
#define LOOKING_RIGHT -0.001f
#define LOOKING_UP -0.001f
#define LOOKING_DOWN 0.001f

static t_ray_collision	get_vertical_collision(t_game *game, float_t angle);
static t_ray_collision	get_horizontal_collision(t_game *game, float_t angle);

t_ray_collision	ray_cast(t_game *game, float_t angle)
{
	t_ray_collision	vertical_collision;
	t_ray_collision	horizontal_collision;

	vertical_collision = get_vertical_collision(game, angle);
	horizontal_collision = get_horizontal_collision(game, angle);
	if (vertical_collision.distance < horizontal_collision.distance)
		return (vertical_collision);
	else
		return (horizontal_collision);
}

static t_ray_collision	get_vertical_collision(t_game *game, float_t angle)
{
	float_t			tan_ang;
	t_ray_collision	collision;
	t_vector2		step;
	size_t			dof;

	tan_ang = tanf(deg_to_rad(angle));
	collision.distance = INFINITY;
	collision.angle = angle;
	dof = 0;
	if (cosf(deg_to_rad(angle)) > LOOKING_LEFT)
	{
		collision.point.x = floorf(game->player.position.x) + 1;
		collision.texture = ft_hshget(game->scene->textures, "WE");
		step = (t_vector2){.x = 1, .y = -tan_ang};
	}
	else if (cosf(deg_to_rad(angle)) < LOOKING_RIGHT)
	{
		collision.point.x = floorf(game->player.position.x) - 0.0001f;
		collision.texture = ft_hshget(game->scene->textures, "EA");
		step = (t_vector2){.x = -1, .y = tan_ang};
	}
	else
	{
		collision.point = game->player.position;
		dof = game->scene->map->width;
	}
	collision.point.y = (game->player.position.x - collision.point.x) * tan_ang
		+ game->player.position.y;
	while (dof < game->scene->map->width)
	{
		if (map_component_at(game->scene->map,
				ivector2_from_vector2(collision.point)) == MAP_WALL)
		{
			dof = game->scene->map->width;
			collision.distance = cosf(deg_to_rad(angle)) * (collision.point.x
					- game->player.position.x) - sinf(deg_to_rad(angle))
				* (collision.point.y - game->player.position.y);
		}
		else
		{
			collision.point = vector2_add(collision.point, step);
			dof++;
		}
	}
	return (collision);
}

static t_ray_collision	get_horizontal_collision(t_game *game, float_t angle)
{
	float_t			tan_ang;
	t_ray_collision	collision;
	size_t			dof;
	t_vector2		step;

	tan_ang = 1.0f / tanf(deg_to_rad(angle));
	collision.distance = INFINITY;
	collision.angle = angle;
	dof = 0;
	if (sinf(deg_to_rad(angle)) > LOOKING_UP)
	{
		collision.point.y = floorf(game->player.position.y) - 0.0001f;
		collision.texture = ft_hshget(game->scene->textures, "NO");
		step = (t_vector2){.x = tan_ang, .y = -1};
	}
	else if (sinf(deg_to_rad(angle)) < LOOKING_DOWN)
	{
		collision.point.x = floorf(game->player.position.x) - 0.0001f;
		collision.texture = ft_hshget(game->scene->textures, "SO");
		step = (t_vector2){.x = -tan_ang, .y = 1};
	}
	else
	{
		collision.point = game->player.position;
		dof = game->scene->map->height;
	}
	collision.point.x = (game->player.position.y - collision.point.y) * tan_ang
		+ game->player.position.x;
	while (dof < game->scene->map->height)
	{
		if (map_component_at(game->scene->map,
				ivector2_from_vector2(collision.point)) == MAP_WALL)
		{
			dof = game->scene->map->height;
			collision.distance = cosf(deg_to_rad(angle)) * (collision.point.x
					- game->player.position.x) - sinf(deg_to_rad(angle))
				* (collision.point.y - game->player.position.y);
		}
		else
		{
			collision.point = vector2_add(collision.point, step);
			dof++;
		}
	}
	return (collision);
}
