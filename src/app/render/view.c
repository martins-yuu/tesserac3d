/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:46:11 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 23:13:40y yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/game/game.h"
#include "app/ray/ray.h"
#include "core/ctx/ctx.h"
#include "core/math/math.h"
#include "render.h"
#include <math.h>
#include <stdint.h>
#include <sys/param.h>

void	render_view(t_game *game)
{
	t_ray_collision	collision;
	float_t			ang;
	int32_t			col;

	ang = normalize_angle(game->player.direction_angle + game->player.fov / 2);
	col = 0;
	while (col < ctx()->width)
	{
		collision = ray_cast(game, ang);
		render_wall(game, collision, col);
		ang = normalize_angle(ang - game->player.fov / ctx()->width);
		col++;
	}
}
