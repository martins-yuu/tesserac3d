/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:55:09 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/01 13:27:40 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_INTERNAL_H
# define SCENE_INTERNAL_H

# include "scene.h"
# include <stdbool.h>

void	scene_build(t_scene *scene, t_array *lines);
bool	scene_is_required_set(const t_scene *scene);
void	scene_add_error(t_scene *scene, t_scene_error error);

#endif
