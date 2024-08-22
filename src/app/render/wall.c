/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:23:13 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 21:39:01 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/game/game.h"
#include "app/ray/ray.h"
#include "core/ctx/ctx.h"
#include <stdint.h>

void	render_wall(t_game *game, t_ray_collision collision, int32_t column)
{
	int32_t	wall_height;
	int32_t	row;

	wall_height = ctx()->height / (collision.distance
			* cosf(deg_to_rad(normalize_angle(game->player.direction_angle)
					- collision.angle)));
	row = 0;
	while (row < wall_height)
	{
		mlx_put_pixel(game->view, column, row, game->scene->floor_color.value);
		row++;
	}
}
