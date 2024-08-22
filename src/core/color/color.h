/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:02:28 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 15:02:12 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define COLOR_RGBA_COMPONENT_COUNT 4
# define COLOR_RGB_COMPONENT_COUNT 3
# define COLOR_COMPONENT_MAX_DIGITS 3

# define COLOR_RED 0xFF0000FF
# define COLOR_GREEN 0x00FF00FF
# define COLOR_BLUE 0x0000FFFF
# define COLOR_CYAN 0x00FFFFFF
# define COLOR_MAGENTA 0xFF00FFFF
# define COLOR_YELLOW 0xFFFF00FF
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_BLACK 0x000000FF
# define COLOR_TRANSPARENT 0x00000000
# define COLOR_GRAY 0x808080FF

typedef union u_color
{
	uint32_t	value;
	struct
	{
		uint8_t	alpha;
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
	};
}				t_color;

typedef struct s_color_result
{
	t_color		color;
	bool		error;
}				t_color_result;

t_color			color(uint32_t v);
t_color			color_from_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_color			color_opacity(t_color c, float_t opacity);
t_color			color_grayscale(t_color c);
t_color			color_lerp(t_color a, t_color b, float_t t);
t_color_result	color_parse_rgb(const char *str);

#endif
