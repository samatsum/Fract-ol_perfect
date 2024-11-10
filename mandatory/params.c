/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 08:37:11 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_param(t_fractal *frac_ptr)
{
	frac_ptr->kinds = 1;
	frac_ptr->width = WINDOW_WIDTH;
	frac_ptr->height = WINDOW_HEIGHT;
	frac_ptr->iterations = 30;
	frac_ptr->zoom = 1;
	frac_ptr->x_min = -2.0;
	frac_ptr->x_max = 0.5;
	frac_ptr->y_min = -1.3;
	frac_ptr->y_max = 1.3;
	frac_ptr->xarrow = 0;
	frac_ptr->yarrow = 0;
	frac_ptr->color = 0xccf1ff;
	frac_ptr->name = "mandelbrot";
	frac_ptr->sum_zoom = 0;
}

void	julia_param(t_fractal *frac_ptr)
{
	frac_ptr->kinds = 2;
	frac_ptr->width = WINDOW_WIDTH;
	frac_ptr->height = WINDOW_HEIGHT;
	frac_ptr->iterations = 30;
	frac_ptr->zoom = 1;
	frac_ptr->x_min = -2.0;
	frac_ptr->x_max = 2.0;
	frac_ptr->y_min = -2.0;
	frac_ptr->y_max = 2.0;
	frac_ptr->xarrow = 0;
	frac_ptr->yarrow = 0;
	frac_ptr->color = 0xccf1ff;
	frac_ptr->name = "julia";
	frac_ptr->sum_zoom = 0;
}
