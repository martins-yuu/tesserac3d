/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 03:58:04 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/06 03:31:15 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

t_ivector2	ivector2_add(t_ivector2 a, t_ivector2 b)
{
	return ((t_ivector2){
		.x = a.x + b.x,
		.y = a.y + b.y,
	});
}

t_ivector2	ivector2_sub(t_ivector2 a, t_ivector2 b)
{
	return ((t_ivector2){
		.x = a.x - b.x,
		.y = a.y - b.y,
	});
}

t_ivector2	ivector2_mul(t_ivector2 a, t_ivector2 b)
{
	return ((t_ivector2){
		.x = a.x * b.x,
		.y = a.y * b.y,
	});
}

t_ivector2	ivector2_div(t_ivector2 a, t_ivector2 b)
{
	return ((t_ivector2){
		.x = a.x / b.x,
		.y = a.y / b.y,
	});
}
