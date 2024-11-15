/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 04:14:44 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	miniburning(int x, int y, t_fractal *burning)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	burning->c.x = (x + burning->xarrow) / burning->zoom
		* (1.0 + 2.5) / (burning->width - 1) - 2.5;
	burning->c.y = (y + burning->yarrow) / burning->zoom
		* (1.0 + 1.0) / (burning->width - 1) - 1.0;
	z0 = burning->c.x;
	z1 = burning->c.y;
	while (i++ < burning->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + burning->c.x;
		z1 = fabs(2.0 * z0 * z1) + burning->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(burning, (int) x, (int) y, (burning->color * i));
			break ;
		}
	}
}

void	burningset(t_fractal *burning)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= burning->width)
	{
		y = -1;
		while (++y <= burning->height)
		{
			miniburning(x, y, burning);
		}
	}
}
