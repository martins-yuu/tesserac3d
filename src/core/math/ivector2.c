/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivector2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 02:54:37 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 22:57:49 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include <stdbool.h>

t_ivector2	ivector2_zero(void)
{
	return ((t_ivector2){
		.x = 0,
		.y = 0,
	});
}

t_ivector2	ivector2_one(void)
{
	return ((t_ivector2){
		.x = 1,
		.y = 1,
	});
}

bool	ivector2_eq(t_ivector2 a, t_ivector2 b)
{
	return (a.x == b.x && a.y == b.y);
}

t_ivector2	ivector2_from_vector2(t_vector2 v)
{
	return ((t_ivector2){
		.x = (int32_t)v.x,
		.y = (int32_t)v.y,
	});
}
