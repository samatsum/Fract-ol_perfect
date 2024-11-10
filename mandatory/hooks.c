/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 08:38:55 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *frac_ptr)
{
	if (keycode == KEY_ESCAPE)
		freeall_closegame(frac_ptr);
	else if (keycode == KEY_LEFT)
		frac_ptr->xarrow -= 50;
	else if (keycode == KEY_DOWN)
		frac_ptr->yarrow += 50;
	else if (keycode == KEY_RIGHT)
		frac_ptr->xarrow += 50;
	else if (keycode == KEY_UP)
		frac_ptr->yarrow -= 50;
	else if (keycode == KEY_EQUAL)
		frac_ptr->color += 200;
	else if (keycode == KEY_MINUS)
		frac_ptr->color -= 200;
	else if (keycode == KEY_I)
		frac_ptr->iterations += 20;
	else if (keycode == KEY_D)
		frac_ptr->iterations -= 20;
	else if (keycode == KEY_M && frac_ptr->kinds == 1)
		mandelbrot_param(frac_ptr);
	else if (keycode == KEY_J && frac_ptr->kinds == 2)
		julia_param(frac_ptr);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *frac_ptr)
{
	if (key_code == 4)
		ft_zoom(x, y, frac_ptr);
	else if (key_code == 5)
		ft_dezoom(x, y, frac_ptr);
	return (0);
}
