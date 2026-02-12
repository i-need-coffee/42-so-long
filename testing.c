/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/12 14:32:48 by sjolliet         ###   ########.fr       */
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
	void		*img;
	void		*img2;
	int			img_width;
	int			img_height;
	int			win_x;
	int			win_y;


	mlx.connect = mlx_init();
	if (!mlx.connect)
		return (1);
	win_x = 23 * 64;
	win_y = 10 * 64;
	mlx.window = mlx_new_window(mlx.connect, win_x, win_y, "so_long");
	if (!mlx.window)
	{
		mlx_destroy_display(mlx.connect);
		free(mlx.connect);
		return (1);
	}
	img = mlx_xpm_file_to_image(mlx.connect, "./textures/floor.xpm",
			&img_width, &img_height);
	if (!img)
		return (1);
	img2 = mlx_xpm_file_to_image(mlx.connect, "./textures/item.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(mlx.connect, mlx.window, img, 0, 0);
	mlx_put_image_to_window(mlx.connect, mlx.window, img2, 0, 0);
	mlx_put_image_to_window(mlx.connect, mlx.window, img, 64, 0);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(mlx.connect);
	mlx_destroy_window(mlx.connect, mlx.window);
	mlx_destroy_display(mlx.connect);
	free(mlx.connect);
	return (0);
}
