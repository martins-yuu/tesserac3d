/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:59:25 by yuuko             #+#    #+#             */
/*   Updated: 2024/08/21 12:59:36 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	error_panic(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	*error_expect(void *ptr, const char *message)
{
	if (!ptr)
		error_panic(message);
	return (ptr);
}
