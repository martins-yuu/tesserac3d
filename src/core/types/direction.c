/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:25:13 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 21:14:03 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/math/math.h"
#include "types.h"
#include <assert.h>

t_ivector2	direction_to_ivector2(t_direction direction)
{
	assert(direction >= DIRECTION_BEGIN && direction < DIRECTION_END);
	return ((t_ivector2[]){
		[DIRECTION_UP] = {.x = 0, .y = -1},
		[DIRECTION_DOWN] = {.x = 0, .y = 1},
		[DIRECTION_LEFT] = {.x = -1, .y = 0},
		[DIRECTION_RIGHT] = {.x = 1, .y = 0},
		[DIRECTION_UP_LEFT] = {.x = -1, .y = -1},
		[DIRECTION_UP_RIGHT] = {.x = 1, .y = -1},
		[DIRECTION_DOWN_LEFT] = {.x = -1, .y = 1},
		[DIRECTION_DOWN_RIGHT] = {.x = 1, .y = 1},
	}[direction]);
}
