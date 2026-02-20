/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:20:25 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/20 15:36:16 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_game *game)
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
				put_img_to_window(game, game->wall_img, x, y);
			else if (c == 'C')
				put_img_to_window(game, game->collectible_img, x, y);
			else if (c == 'E')
				put_img_to_window(game, game->exit_img, x, y);
			else if (c == 'P')
				put_img_to_window(game, game->player_img, x, y);
			else
				put_img_to_window(game, game->floor_img, x, y);
			x++;
		}
		y++;
	}
}
