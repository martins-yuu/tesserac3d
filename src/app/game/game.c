/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:57:03 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 03:48:03 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/player/player.h"
#include "app/scene/scene.h"
#include "core/ctx/constants.h"
#include "core/ctx/ctx.h"
#include "core/math/math.h"
#include "game.h"
#include "game_internal.h"
#include <sys/param.h>
#include <sys/types.h>

static void	init_game(t_game *game, t_scene *scene);

void	game_run(t_scene *scene)
{
	t_game	game;

	init_game(&game, scene);
	ctx_on_loop(game_loop, &game);
	ctx_on_key(game_handle_keys, &game);
	ctx_end();
}

static void	init_game(t_game *game, t_scene *scene)
{
	static const u_int32_t	minimap_size = MIN(WIDTH, HEIGHT) / 2;
	static const t_ivector2	minimap_offset = {.x = 10, .y = 10};

	*game = (t_game){
		.scene = scene,
		.view = ctx_image_new(WIDTH, HEIGHT),
		.minimap = ctx_image_new(minimap_size, minimap_size),
		.shape = ctx_image_new(minimap_size, minimap_size),
	};
	player_init(&game->player, game->scene);
	ctx_image_display(game->view, ivector2_zero().x, ivector2_zero().y);
	ctx_image_display(game->minimap, minimap_offset.x, minimap_offset.y);
	ctx_image_display(game->shape, minimap_offset.x, minimap_offset.y);
}
