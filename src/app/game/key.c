/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:04:41 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 17:04:27 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "app/game/game.h"
#include "core/ctx/ctx.h"

void	game_handle_keys(mlx_key_data_t keydata, void *game)
{
	t_game	*g;

	g = game;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(ctx());
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		g->minimap->enabled = !g->minimap->enabled;
}
