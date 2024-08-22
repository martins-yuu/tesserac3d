/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:22:18 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 22:49:58 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "core/color/color.h"
#include "core/math/math.h"
#include "draw.h"
#include "draw_internal.h"
#include "ft_stdlib.h"
#include <stdbool.h>
#include <stdint.h>

static void	init_line_data(t_line_data *d, t_ivector2 p1, t_ivector2 p2);

void	draw_line(mlx_image_t *image, t_ivector2 p1, t_ivector2 p2,
		t_color color)
{
	t_line_data	d;

	init_line_data(&d, p1, p2);
	while (true)
	{
		mlx_put_pixel(image, p1.x, p1.y, color.value);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		if (d.error * 2 >= d.dy)
		{
			if (p1.x == p2.x)
				break ;
			d.error += d.dy;
			p1.x += d.sx;
		}
		if (d.error * 2 <= d.dx)
		{
			if (p1.y == p2.y)
				break ;
			d.error += d.dx;
			p1.y += d.sy;
		}
	}
}

void	draw_rectangle(mlx_image_t *image, t_rectangle rectangle, t_color color)
{
	t_ivector2	pos;

	pos.y = 0;
	while (pos.y < rectangle.size.y)
	{
		pos.x = 0;
		while (pos.x < rectangle.size.x)
		{
			mlx_put_pixel(image, rectangle.position.x + pos.x,
				rectangle.position.y + pos.y, color.value);
			pos.x++;
		}
		pos.y++;
	}
}

void	clear_background(mlx_image_t *image, t_color color)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, color.value);
			x++;
		}
		y++;
	}
}

static void	init_line_data(t_line_data *d, t_ivector2 p1, t_ivector2 p2)
{
	d->dx = ft_abs(p2.x - p1.x);
	d->sx = (p1.x < p2.x) * 2 - 1;
	d->dy = -ft_abs(p2.y - p1.y);
	d->sy = (p1.y < p2.y) * 2 - 1;
	d->error = d->dx + d->dy;
}
