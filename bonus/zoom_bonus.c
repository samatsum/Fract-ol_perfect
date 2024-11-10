/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:17:57 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	pixel_to_complex_x(double pixel_x, t_fractal *frac_ptr)
{
	return (frac_ptr->x_min + (pixel_x / (double)frac_ptr->width) * \
		(frac_ptr->x_max - frac_ptr->x_min));
}

double	pixel_to_complex_y(double pixel_y, t_fractal *frac_ptr)
{
	return (frac_ptr->y_min + (pixel_y / (double)frac_ptr->height) * \
		(frac_ptr->y_max - frac_ptr->y_min));
}

void	ft_zoom(double x, double y, t_fractal *frac_ptr)
{
	double	center_x;
	double	center_y;
	double	range_x;
	double	range_y;

	center_x = pixel_to_complex_x(x, frac_ptr);
	center_y = pixel_to_complex_y(y, frac_ptr);
	frac_ptr->zoom = ZOOM_LEVEL;
	frac_ptr->sum_zoom++;
	range_x = (frac_ptr->x_max - frac_ptr->x_min) / frac_ptr->zoom;
	range_y = (frac_ptr->y_max - frac_ptr->y_min) / frac_ptr->zoom;
	frac_ptr->x_min = center_x - range_x / 2;
	frac_ptr->x_max = center_x + range_x / 2;
	frac_ptr->y_min = center_y - range_y / 2;
	frac_ptr->y_max = center_y + range_y / 2;
	frac_ptr->iterations += 1;
}

void	ft_dezoom(double x, double y, t_fractal *frac_ptr)
{
	double	center_x;
	double	center_y;
	double	range_x;
	double	range_y;

	center_x = (frac_ptr->x_min + frac_ptr->x_max) / 2;
	center_y = (frac_ptr->y_min + frac_ptr->y_max) / 2;
	frac_ptr->zoom = 1 / ZOOM_LEVEL;
	frac_ptr->sum_zoom--;
	range_x = (frac_ptr->x_max - frac_ptr->x_min) / frac_ptr->zoom;
	range_y = (frac_ptr->y_max - frac_ptr->y_min) / frac_ptr->zoom;
	frac_ptr->x_min = center_x - range_x / 2;
	frac_ptr->x_max = center_x + range_x / 2;
	frac_ptr->y_min = center_y - range_y / 2;
	frac_ptr->y_max = center_y + range_y / 2;
	frac_ptr->iterations -= 1;
}

// void	ft_zoom(double x, double y, t_fractal *frac_ptr)
// {
// 	double	center_x;
// 	double	center_y;
// 	double	scope_mag;

// 	center_x = pixel_to_complex_x(x, frac_ptr);
// 	center_y = pixel_to_complex_y(y, frac_ptr);
// 	frac_ptr->zoom = ZOOM_LEVEL;
// 	scope_mag = 1 / frac_ptr->zoom;
// 	frac_ptr->x_min = frac_ptr->x_min * scope_mag + (1 - scope_mag) * center_x;
// 	frac_ptr->y_min = frac_ptr->y_min * scope_mag + (1 - scope_mag) * center_y;
// 	frac_ptr->x_max = frac_ptr->x_max * scope_mag + (1 - scope_mag) * center_x;
// 	frac_ptr->y_max = frac_ptr->y_max * scope_mag + (1 - scope_mag) * center_y;
// 	frac_ptr->iterations += 1;
// }

// void	ft_dezoom(double x, double y, t_fractal *frac_ptr)
// {
// 	double	center_x;
// 	double	center_y;
// 	double	scope_mag;

// 	frac_ptr->zoom = 1 / ZOOM_LEVEL;
// 	center_x = (frac_ptr->x_min + frac_ptr->x_max) / 2;
// 	center_y = (frac_ptr->y_min + frac_ptr->y_max) / 2;
// 	scope_mag = 1 / frac_ptr->zoom;
// 	frac_ptr->x_min = frac_ptr->x_min * scope_mag + (1 - scope_mag) * center_x;
// 	frac_ptr->y_min = frac_ptr->y_min * scope_mag + (1 - scope_mag) * center_y;
// 	frac_ptr->x_max = frac_ptr->x_max * scope_mag + (1 - scope_mag) * center_x;
// 	frac_ptr->y_max = frac_ptr->y_max * scope_mag + (1 - scope_mag) * center_y;
// 	frac_ptr->iterations -= 1;
// }
