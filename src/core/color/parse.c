/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:50:44 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 15:01:47 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "common/error.h"
#include "ft_arraylist.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

t_color_result	color_parse_rgb(const char *str)
{
	t_array		*rgb;
	t_string	*component;
	size_t		i;
	int32_t		tmp[COLOR_RGB_COMPONENT_COUNT];

	if (ft_strcount(str, ',') != COLOR_RGB_COMPONENT_COUNT - 1)
		return ((t_color_result){.error = true});
	rgb = error_expect(ft_stnsplit(str, ','), "ft_stnsplit");
	if (ft_arrsize(rgb) != COLOR_RGB_COMPONENT_COUNT)
		return (ft_stnfreesplit(rgb), (t_color_result){.error = true});
	i = 0;
	while (i < COLOR_RGB_COMPONENT_COUNT)
	{
		component = ft_arrat(rgb, i);
		if (!ft_stntonumeric(*component))
			return (ft_stnfreesplit(rgb), (t_color_result){.error = true});
		if (ft_stnlen(*component) > COLOR_COMPONENT_MAX_DIGITS)
			return (ft_stnfreesplit(rgb), (t_color_result){.error = true});
		tmp[i] = ft_atoi(*component);
		if (tmp[i] < 0 || tmp[i] > UINT8_MAX)
			return (ft_stnfreesplit(rgb), (t_color_result){.error = true});
		i++;
	}
	return (ft_stnfreesplit(rgb), (t_color_result){color_from_rgba(tmp[0],
			tmp[1], tmp[2], UINT8_MAX), false});
}
