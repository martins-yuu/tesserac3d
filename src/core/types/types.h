/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:24:25 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 14:58:26 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "core/math/math.h"
# include <math.h>
# include <sys/types.h>

typedef enum t_orientation
{
	ORIENTATION_ILLEGAL = 0,
	ORIENTATION_NORTH,
	ORIENTATION_SOUTH,
	ORIENTATION_WEST,
	ORIENTATION_EAST,
	ORIENTATION_END,
	ORIENTATION_BEGIN = ORIENTATION_ILLEGAL + 1,
	ORIENTATION_COUNT = ORIENTATION_END - ORIENTATION_BEGIN
}				t_orientation;

typedef enum t_direction
{
	DIRECTION_ILLEGAL = 0,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP_LEFT,
	DIRECTION_UP_RIGHT,
	DIRECTION_DOWN_LEFT,
	DIRECTION_DOWN_RIGHT,
	DIRECTION_END,
	DIRECTION_BEGIN = DIRECTION_ILLEGAL + 1,
	DIRECTION_COUNT = DIRECTION_END - DIRECTION_BEGIN
}				t_direction;

const char		*orientation_to_string(t_orientation orientation);
float_t			orientation_to_float(t_orientation orientation);
t_orientation	orientation_from_string(const char *name);
t_orientation	orientation_from_char(char c);
t_ivector2		direction_to_ivector2(t_direction direction);

#endif
