/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:37:06 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 23:33:17 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/game/game.h"
#include "app/player/player.h"
#include "app/render/render.h"
#include "core/color/color.h"
#include "core/ctx/ctx.h"
#include "core/draw/draw.h"
#include "core/types/types.h"
#include "game_internal.h"

static void	update_player(t_game *game);

void	game_loop(void *game)
{
	t_game	*g;

	g = game;
	clear_background(g->view, color(COLOR_BLACK));
	update_player(g);
	render_minimap(g);
	render_view(g);
}

static void	update_player(t_game *game)
{
	if (mlx_is_key_down(ctx(), MLX_KEY_W))
		player_move(&game->player, game->scene->map, DIRECTION_UP);
	if (mlx_is_key_down(ctx(), MLX_KEY_S))
		player_move(&game->player, game->scene->map, DIRECTION_DOWN);
	if (mlx_is_key_down(ctx(), MLX_KEY_A))
		player_strafe(&game->player, game->scene->map, DIRECTION_LEFT);
	if (mlx_is_key_down(ctx(), MLX_KEY_D))
		player_strafe(&game->player, game->scene->map, DIRECTION_RIGHT);
	if (mlx_is_key_down(ctx(), MLX_KEY_LEFT))
		player_yaw(&game->player, game->scene->map, DIRECTION_LEFT);
	if (mlx_is_key_down(ctx(), MLX_KEY_RIGHT))
		player_yaw(&game->player, game->scene->map, DIRECTION_RIGHT);
}
