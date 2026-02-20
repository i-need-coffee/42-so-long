/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/20 15:36:02 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_and_exit("The program should have one parameter (.ber file)");
	ft_bzero(&game, sizeof(game));
	parse_map(argv[1], &game);
	check_map_path(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		free_map_and_exit(game.map, "Mlx failed to be initialized");
	check_map_size(&game);
	handle_window(&game);
	init_images(&game);
	draw_map(&game);
	print_start();
	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	close_game(&game);
	return (0);
}
