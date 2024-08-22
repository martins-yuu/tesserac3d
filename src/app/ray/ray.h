/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:16:12 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 22:01:35 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "MLX42/MLX42.h"
# include "app/game/game.h"
# include "core/math/math.h"
# include <math.h>

typedef struct s_ray_collision
{
	float_t		distance;
	t_vector2	point;
	float_t		angle;
	mlx_image_t	*texture;
}				t_ray_collision;

t_ray_collision	ray_cast(t_game *game, float_t angle);

#endif
