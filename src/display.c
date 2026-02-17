/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:39:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 15:43:17 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->size_x * TILE_SIZE,
			game->size_y * TILE_SIZE, "so_long");
	if (!game->mlx_win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Window failed to be initialized");
	}
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map_data(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
	return (0);
}
