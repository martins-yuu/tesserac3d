/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:37:11 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/12 18:58:04 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "core/ctx/ctx.h"

void	ctx_on_loop(void (*handle)(void *), void *param)
{
	if (!mlx_loop_hook(ctx(), handle, param))
		ctx_panic();
}

void	ctx_on_key(mlx_keyfunc handle, void *param)
{
	mlx_key_hook(ctx(), handle, param);
}

void	ctx_on_mouse(mlx_mousefunc handle, void *param)
{
	mlx_mouse_hook(ctx(), handle, param);
}

void	ctx_on_resize(mlx_resizefunc handle, void *param)
{
	mlx_resize_hook(ctx(), handle, param);
}
