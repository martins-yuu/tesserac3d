/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:05:05 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/13 02:40:55 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INTERNAL_H
# define GAME_INTERNAL_H

# include "MLX42/MLX42.h"

void	game_loop(void *game);
void	game_handle_keys(mlx_key_data_t keydata, void *game);

#endif
