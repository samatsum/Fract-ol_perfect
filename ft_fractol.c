/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 04:16:59 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractalsetup(t_fractal *fractal, int *fractal_kinds)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (*fractal_kinds == 1)
		mandelbrotset(fractal);
	else if (*fractal_kinds == 2)
		juliaset(fractal);
	else if (*fractal_kinds == 3)
		burningset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	int				fractal_kinds;
	t_fractal		fractal;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			mandelbrot_param(&fractal, argv[1], &fractal_kinds);
		else if (!ft_strncmp(argv[1], "julia", 5))
			julia_param(&fractal, argv[1], &fractal_kinds);
		else if (!ft_strncmp(argv[1], "burning", 7))
			burning_param(&fractal, argv[1], &fractal_kinds);
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, fractal.width,
				fractal.height, fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
		fractalsetup(&fractal, &fractal_kinds);
		mlx_key_hook(fractal.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}
