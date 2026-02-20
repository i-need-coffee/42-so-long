/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:39:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/20 15:34:51 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	init_images(t_game *game)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &tile_size, &tile_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&tile_size, &tile_size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&tile_size, &tile_size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&tile_size, &tile_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&tile_size, &tile_size);
	if (!game->collectible_img || !game->exit_img || !game->floor_img
		|| !game->player_img || !game->wall_img)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Images failed to be initialized");
	}
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->wall_img);
}

void	put_img_to_window(t_game *game, void *img, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}

void	check_map_size(t_game *game)
{
	int	screen_w;
	int	screen_h;
	int	map_w;
	int	map_h;

	map_w = game->size_x * TILE_SIZE;
	map_h = game->size_y * TILE_SIZE;
	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	if (map_w > screen_w || map_h > screen_h)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Map too large for screen");
	}
}
