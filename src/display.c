/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:39:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/16 22:12:31 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_window(t_mlx_data *mlx, t_map_data *map)
{
	mlx->window = mlx_new_window(mlx->connect, map->size_x * TILE_SIZE, map->size_y * TILE_SIZE, "so_long");
	if (!mlx->window)
	{
		mlx_destroy_display(mlx->connect);
		free(mlx->connect);
		free_map_and_exit(map->data, "Window failed to be initialized");
	}
}
 