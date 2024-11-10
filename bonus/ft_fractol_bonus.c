/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	fractal_setup(t_fractal *frac_ptr)
{
	mlx_destroy_image(frac_ptr->mlx, frac_ptr->img);
	frac_ptr->img = mlx_new_image(frac_ptr->mlx,
			frac_ptr->width, frac_ptr->height);
	frac_ptr->addr = mlx_get_data_addr(frac_ptr->img, &frac_ptr->bits_per_pixel,
			&frac_ptr->line_length, &frac_ptr->endian);
	if (frac_ptr->kinds == 1)
		mandelbrot_set(frac_ptr);
	else if (frac_ptr->kinds == 2)
		julia_set(frac_ptr);
	else if (frac_ptr->kinds == 3)
		burning_set(frac_ptr);
	mlx_put_image_to_window(frac_ptr->mlx, frac_ptr->win, frac_ptr->img, 0, 0);
	ft_printf("Name = %s | ", frac_ptr->name);
	ft_printf("Iterations = %d | ", frac_ptr->iterations);
	ft_printf("Zoom = ZOOMLEVEL ^ %d \n", frac_ptr->sum_zoom);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	format_check(argc, argv, &fractal);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, fractal.width,
			fractal.height, fractal.name);
	fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
	fractal_setup(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, freeall_closegame, &fractal);
	mlx_loop_hook(fractal.mlx, fractal_setup, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
