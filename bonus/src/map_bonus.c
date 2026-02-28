/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:20:25 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/28 14:12:40 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	choose_img_to_draw(t_game *game, char c, int x, int y);
static void	put_img_to_window(t_game *game, void *img, int x, int y);

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choose_img_to_draw(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
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

static void	choose_img_to_draw(t_game *game, char c, int x, int y)
{
	if (c == '1')
		put_img_to_window(game, game->wall_img, x, y);
	else if (c == 'C')
		put_img_to_window(game, game->collectible_img, x, y);
	else if (c == 'E')
		put_img_to_window(game, game->exit_img, x, y);
	else if (c == 'P')
	{
		if (game->total_c == game->num_c)
			put_img_to_window(game, game->player_img, x, y);
		else if (game->num_c == 0)
			put_img_to_window(game, game->player_img_3, x, y);
		else
			put_img_to_window(game, game->player_img_2, x, y);
	}
	else if (c == 'X')
		put_img_to_window(game, game->enemy_img, x, y);
	else
		put_img_to_window(game, game->floor_img, x, y);
}

static void	put_img_to_window(t_game *game, void *img, int x, int y)
{
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
}
