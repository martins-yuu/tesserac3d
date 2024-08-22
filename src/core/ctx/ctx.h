/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:51:18 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/12 20:14:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "MLX42/MLX42.h"
# include "core/math/math.h"

mlx_t		*ctx(void);
void		ctx_end(void);
void		ctx_panic(void) __attribute__((noreturn));
t_ivector2	ctx_max(void);
t_ivector2	ctx_center(void);
mlx_image_t	*ctx_image_new(uint32_t width, uint32_t height);
int32_t		ctx_image_display(mlx_image_t *image, int32_t x, int32_t y);
void		ctx_image_resize(mlx_image_t *image, uint32_t new_width,
				uint32_t new_height);
t_ivector2	ctx_image_max(mlx_image_t *image);
t_ivector2	ctx_image_center(mlx_image_t *image);
void		ctx_on_loop(void (*handle)(void *), void *param);
void		ctx_on_key(mlx_keyfunc handle, void *param);
void		ctx_on_mouse(mlx_mousefunc handle, void *param);
void		ctx_on_resize(mlx_resizefunc handle, void *param);

#endif
