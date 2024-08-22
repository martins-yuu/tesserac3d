/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:00:11 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 14:58:42 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "types.h"
#include <assert.h>
#include <math.h>
#include <stddef.h>

const char	*orientation_to_string(t_orientation orientation)
{
	assert(orientation >= ORIENTATION_ILLEGAL && orientation < ORIENTATION_END);
	return ((const char *[]){
		[ORIENTATION_ILLEGAL] = NULL,
		[ORIENTATION_NORTH] = "N",
		[ORIENTATION_SOUTH] = "S",
		[ORIENTATION_WEST] = "W",
		[ORIENTATION_EAST] = "E",
	}[orientation]);
}

char	orientntaion_to_char(t_orientation orientation)
{
	assert(orientation != ORIENTATION_ILLEGAL);
	return (*orientation_to_string(orientation));
}

float	orientation_to_float(t_orientation orientation)
{
	assert(orientation != ORIENTATION_ILLEGAL);
	return ((float_t[]){
		[ORIENTATION_NORTH] = 90.0f,
		[ORIENTATION_SOUTH] = 270.0f,
		[ORIENTATION_WEST] = 180.0f,
		[ORIENTATION_EAST] = 0.0f,
	}[orientation]);
}

t_orientation	orientation_from_string(const char *name)
{
	size_t		i;
	const char	*identifier;

	i = ORIENTATION_BEGIN;
	while (i < ORIENTATION_END)
	{
		identifier = orientation_to_string(i);
		if (ft_strncmp(name, identifier, ft_strlen(identifier) + 1) == 0)
			return ((t_orientation)i);
		i++;
	}
	return (ORIENTATION_ILLEGAL);
}

t_orientation	orientation_from_char(char c)
{
	const char	name[] = {c, '\0'};

	return (orientation_from_string(name));
}
