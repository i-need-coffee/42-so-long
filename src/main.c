/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 14:18:45 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_and_exit("The program should have one parameter (.ber file)");
	ft_bzero(&game, sizeof(game));
	init_and_check_map(argv[1], &game);
	check_map_path(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		free_map_and_exit(game.map, "Mlx failed to be initialized");
	handle_window(&game);
	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
