/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/16 22:12:50 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_data	map;
	t_mlx_data	mlx;

	if (argc != 2)
		error_and_exit("The program should have one parameter (.ber file)");
	init_and_check_map(argv[1], &map);
	check_map_path(&map);
	mlx.connect = mlx_init();
	if (!mlx.connect)
		free_map_and_exit(map.data, "Mlx failed to be initialized");
	handle_window(&mlx, &map);
	mlx_loop(mlx.connect);
	free_map_data(map.data);
	mlx_destroy_window(mlx.connect, mlx.window);
	mlx_destroy_display(mlx.connect);
	free(mlx.connect);
	return (0);
}
