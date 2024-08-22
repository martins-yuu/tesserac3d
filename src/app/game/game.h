/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:05:15 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 02:41:04 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "MLX42/MLX42.h"
# include "app/player/player.h"
# include "app/scene/scene.h"

typedef struct s_game
{
	t_scene		*scene;
	t_player	player;
	mlx_image_t	*view;
	mlx_image_t	*minimap;
	mlx_image_t	*shape;
}				t_game;

void			game_run(t_scene *scene);

#endif
