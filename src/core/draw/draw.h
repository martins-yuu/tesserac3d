/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:22:02 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 22:13:03 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "MLX42/MLX42.h"
# include "core/color/color.h"
# include "core/math/math.h"

typedef struct s_rectangle
{
	t_ivector2	position;
	t_ivector2	size;
}				t_rectangle;

void			draw_line(mlx_image_t *image, t_ivector2 p1, t_ivector2 p2,
					t_color color);
void			clear_background(mlx_image_t *image, t_color color);
void			draw_rectangle(mlx_image_t *image, t_rectangle rectangle,
					t_color color);

#endif
