/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:11:00 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 15:19:12 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "constants.h"
#include "core/math/math.h"
#include "ft_stdio.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

mlx_t	*ctx(void)
{
	static mlx_t	*instance = NULL;

	if (instance == NULL)
	{
		instance = mlx_init(WIDTH, HEIGHT, TITLE, true);
		if (!instance)
		{
			ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		mlx_set_window_limit(instance, WIDTH, HEIGHT, -1, -1);
	}
	return (instance);
}

void	ctx_end(void)
{
	mlx_loop(ctx());
	mlx_terminate(ctx());
}

void	ctx_panic(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	mlx_close_window(ctx());
	exit(EXIT_FAILURE);
}

t_ivector2	ctx_max(void)
{
	return ((t_ivector2){
		.x = ctx()->width,
		.y = ctx()->height,
	});
}

t_ivector2	ctx_center(void)
{
	return ((t_ivector2){
		.x = ctx()->width / 2,
		.y = ctx()->height / 2,
	});
}
