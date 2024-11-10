/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	minijulia(int x, int y, t_fractal *frac_ptr)
{
	t_complex	z0;
	t_complex	z1;
	int			i;

	z0 = mappoint(frac_ptr, x, y);
	i = 0;
	while (i < frac_ptr->iterations)
	{
		z1 = complex_add(complex_sqr(z0), frac_ptr->c);
		if (z1.x * z1.x + z1.y * z1.y > 4)
		{
			my_mlx_pixel_put(frac_ptr, x, y, \
				frac_ptr->color * i / frac_ptr->iterations);
			break ;
		}
		z0 = z1;
		i++;
	}
}

void	julia_set(t_fractal *frac_ptr)
{
	int	x;
	int	y;
	int	i;

	pan_arrow(frac_ptr);
	x = -1;
	while (++x < frac_ptr->width)
	{
		y = -1;
		while (++y < frac_ptr->height)
			minijulia(x, y, frac_ptr);
	}
}
