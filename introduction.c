int	main(void)
{
	void *mlx;
	void *mlx_window;
	int y;
	int x;
	int width;
	int height;
	int size;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	width = 500;
	height = 500;
	mlx_window = mlx_new_window(mlx, width, height, "A beautiful window");
	size = 50;
	y = size;
	while (y < height - size)
	{
		x = size;
		while (x < width - size)
		{
			mlx_pixel_put(mlx, mlx_window, y, x, rand() % 0x1000000);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx, mlx_window, width * 0.8, height * 0.95, rand(),
		"My pollock");
	mlx_loop(mlx);
	return (0);
}