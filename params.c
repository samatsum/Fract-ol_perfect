/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 04:12:58 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_param(t_fractal *fractal, char *name, int *fractal_kinds)
{
	*fractal_kinds = 1;
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 270;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}

void	julia_param(t_fractal *fractal, char *name, int *fractal_kinds)
{
	*fractal_kinds = 2;
	fractal->width = 1280;
	fractal->height = 720;
	fractal->c.x = -0.7;
	fractal->c.y = 0.27015;
	fractal->radius = 3;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}

void	burning_param(t_fractal *fractal, char *name, int *fractal_kinds)
{
	*fractal_kinds = 3;
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 8.157307;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 1710.0;
	fractal->yarrow = 4530.0;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}
