/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 08:34:07 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	minimandel(int x, int y, t_fractal *frac_ptr)
{
	int		i;
	double	c_x;
	double	c_y;
	double	tempc_x;

	i = 0;
	c_x = frac_ptr->c.x;
	c_y = frac_ptr->c.y;
	while (i++ < frac_ptr->iterations)
	{
		tempc_x = c_x * c_x - c_y * c_y + frac_ptr->c.x;
		c_y = 2.0 * c_x * c_y + frac_ptr->c.y;
		c_x = tempc_x;
		if (c_x * c_x + c_y * c_y > 4)
		{
			my_mlx_pixel_put(frac_ptr, x, y, (frac_ptr->color * i) / \
				frac_ptr->iterations);
			break ;
		}
	}
}

void	mandelbrot_set(t_fractal *frac_ptr)
{
	int		x;
	int		y;

	pan_arrow(frac_ptr);
	x = -1;
	while (++x <= frac_ptr->width)
	{
		frac_ptr->c.x = frac_ptr->x_min + (x / (double)frac_ptr->width) * \
			(frac_ptr->x_max - frac_ptr->x_min);
		y = -1;
		while (++y <= frac_ptr->height)
		{
			frac_ptr->c.y = frac_ptr->y_min + (y / (double)frac_ptr->height) * \
				(frac_ptr->y_max - frac_ptr->y_min);
			minimandel(x, y, frac_ptr);
		}
	}
}
