/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:31:30 by yuuko             #+#    #+#             */
/*   Updated: 2024/09/09 17:33:06 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_INTERNAL_H
# define DRAW_INTERNAL_H

# include <stdint.h>

typedef struct s_line_data
{
	int32_t	dx;
	int32_t	dy;
	int32_t	sx;
	int32_t	sy;
	int32_t	error;
}			t_line_data;

#endif
