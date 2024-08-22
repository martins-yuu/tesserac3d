/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:22:45 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 19:53:20 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "app/game/game.h"
# include "app/ray/ray.h"

void	render_view(t_game *game);
void	render_minimap(t_game *game);
void	render_ray(t_game *game, t_ray_collision ray);
void	render_wall(t_game *game, t_ray_collision collision, int32_t column);

#endif
