/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:27:33 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 21:27:20 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/error.h"
#include "ft_arraylist.h"
#include "ft_stdio.h"
#include "scene.h"
#include <unistd.h>

const char	*scene_error_to_string(t_scene_error err)
{
	return ((const char *[]){
		[SCENE_SUCCESS] = "Success",
		[SCENE_INVALID_EXTENSION] = "Invalid extension",
		[SCENE_INVALID_FILE] = "Invalid file",
		[SCENE_INVALID_ELEMENT] = "Invalid element",
		[SCENE_MISSING_ELEMENT] = "Missing element",
		[SCENE_INVALID_MAP] = "Invalid map",
		[SCENE_INVALID_COLOR] = "Invalid color",
		[SCENE_INVALID_TEXTURE] = "Invalid texture",
	}[err]);
}

void	scene_add_error(t_scene *scene, t_scene_error error)
{
	ft_putendl_fd((char *)scene_error_to_string(error), STDERR_FILENO);
	if (!ft_arrappend(scene->errors, &error))
		error_panic("ft_arrappend");
}
