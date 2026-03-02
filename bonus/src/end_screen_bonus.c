/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:59:45 by sjolliet          #+#    #+#             */
/*   Updated: 2026/03/02 13:21:52 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->game_over_img, 0, 0);
}
