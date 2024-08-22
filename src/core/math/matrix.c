/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:52 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 22:57:54 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include <math.h>

t_matrix	matrix_mul(t_matrix a, t_matrix b)
{
	return ((t_matrix){
		.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20,
		.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21,
		.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22,
		.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20,
		.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21,
		.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22,
		.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20,
		.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21,
		.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22,
	});
}

t_vector2	matrix_mul_vector2(t_matrix m, t_vector2 v)
{
	return ((t_vector2){
		.x = m.m00 * v.x + m.m01 * v.y + m.m02 * v.w,
		.y = m.m10 * v.x + m.m11 * v.y + m.m12 * v.w,
		.w = m.m20 * v.x + m.m21 * v.y + m.m22 * v.w,
	});
}

// clang-format off
t_matrix	matrix_translate(t_vector2 position)
{
	return ((t_matrix){
		1.0f, 0.0f, position.x,
		0.0f, 1.0f, position.y,
		0.0f, 0.0f, 1.0f,
	});
}
// clang-format on

// clang-format off
t_matrix	matrix_scale(t_vector2 scale)
{
	return ((t_matrix){
		scale.x, 0.0f, 0.0f,
		0.0f, scale.y, 0.0f,
		0.0f, 0.0f, 1.0f,
	});
}
// clang-format on

// clang-format off
t_matrix	matrix_rotate(float_t angle_degrees)
{
	float_t	rad;

	rad = deg_to_rad(angle_degrees);
	return ((t_matrix){
		cosf(rad), sinf(rad), 0.0f,
		-sinf(rad), cosf(rad), 0.0f,
		0.0f, 0.0f, 1.0f,
	});
}
// clang-format on
