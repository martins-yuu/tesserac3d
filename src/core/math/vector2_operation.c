/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 03:58:04 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 03:31:21 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_vector2	vector2_add(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){
		.x = a.x + b.x,
		.y = a.y + b.y,
	});
}

t_vector2	vector2_sub(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){
		.x = a.x - b.x,
		.y = a.y - b.y,
	});
}

t_vector2	vector2_mul(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){
		.x = a.x * b.x,
		.y = a.y * b.y,
	});
}

t_vector2	vector2_div(t_vector2 a, t_vector2 b)
{
	return ((t_vector2){
		.x = a.x / b.x,
		.y = a.y / b.y,
	});
}
