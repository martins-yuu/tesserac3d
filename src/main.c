/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:39:20 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/11 02:46:03 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app/game/game.h"
#include "app/scene/scene.h"
#include "ft_stdio.h"
#include <stdlib.h>
#include <unistd.h>

#define PROGRAM_NAME "cub3D"

int	main(int argc, char *argv[])
{
	t_scene_result	res;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./" PROGRAM_NAME " <map>." SCENE_FILE_EXTENSION,
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	res = scene_parse(argv[1]);
	if (res.error)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd((char *)scene_error_to_string(res.error), STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	scene_print(res.scene);
	game_run(res.scene);
	scene_free(res.scene);
	return (EXIT_SUCCESS);
}
