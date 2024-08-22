/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:50:26 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 15:00:17 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float_t	deg_to_rad(float_t degrees)
{
	return (degrees * M_PI / 180.0f);
}

float_t	rad_to_deg(float_t radians)
{
	return (radians * (180.0f / M_PI));
}

float_t	normalize_angle(float_t angle_degrees)
{
	angle_degrees = fmodf(angle_degrees, 360.0f);
	if (angle_degrees < 0)
		angle_degrees += 360.0f;
	return (angle_degrees);
}
