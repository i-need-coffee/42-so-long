/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/08 20:53:05 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(mlx->connect, mlx->window);
		mlx_destroy_display(mlx->connect);
		free(mlx->connect);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_mlx_data	mlx;

	mlx.connect = mlx_init();
	if (!mlx.connect)
		return (1);
	mlx.window = mlx_new_window(mlx.connect, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (!mlx.window)
	{
		mlx_destroy_display(mlx.connect);
		free(mlx.connect);
		return (1);
	}
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(mlx.connect);
	mlx_destroy_window(mlx.connect, mlx.window);
	mlx_destroy_display(mlx.connect);
	free(mlx.connect);
	return (0);
}
