/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:20:25 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 17:34:50 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (c == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (c == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}
