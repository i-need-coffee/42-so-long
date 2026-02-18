/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:45:53 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/18 13:54:21 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	if (keysym == XK_Up || keysym == XK_w)
		move_player_up(game);
	if (keysym == XK_Down || keysym == XK_s)
		move_player_down(game);
	if (keysym == XK_Left || keysym == XK_a)
		move_player_left(game);
	if (keysym == XK_Right || keysym == XK_d)
		move_player_right(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map_data(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
