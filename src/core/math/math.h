/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:28:21 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 14:59:53 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <math.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_vector2
{
	float_t	x;
	float_t	y;
	float_t	w;
}			t_vector2;

typedef struct s_ivector2
{
	int32_t	x;
	int32_t	y;
}			t_ivector2;

typedef struct s_matrix
{
	float_t	m00;
	float_t	m01;
	float_t	m02;
	float_t	m10;
	float_t	m11;
	float_t	m12;
	float_t	m20;
	float_t	m21;
	float_t	m22;
}			t_matrix;

t_ivector2	ivector2_zero(void);
t_ivector2	ivector2_one(void);
bool		ivector2_eq(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_from_vector2(t_vector2 v);
t_ivector2	ivector2_add(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_sub(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_mul(t_ivector2 a, t_ivector2 b);
t_ivector2	ivector2_div(t_ivector2 a, t_ivector2 b);
t_vector2	vector2_zero(void);
t_vector2	vector2_one(void);
t_vector2	vector2_add(t_vector2 a, t_vector2 b);
t_vector2	vector2_sub(t_vector2 a, t_vector2 b);
t_vector2	vector2_mul(t_vector2 a, t_vector2 b);
t_vector2	vector2_div(t_vector2 a, t_vector2 b);
t_matrix	matrix_mul(t_matrix a, t_matrix b);
t_vector2	matrix_mul_vector2(t_matrix m, t_vector2 v);
t_matrix	matrix_translate(t_vector2 position);
t_matrix	matrix_scale(t_vector2 scale);
t_matrix	matrix_rotate(float_t angle_deg);
float_t		deg_to_rad(float_t degrees);
float_t		rad_to_deg(float_t radians);
float_t		normalize_angle(float_t angle_degrees);

#endif
