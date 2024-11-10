/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:10:44 by samatsum          #+#    #+#             */
/*   Updated: 2024/11/11 07:30:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	mappoint(t_fractal *frac_ptr, double x, double y)
{
	t_complex	c;

	c.x = frac_ptr->x_min + (x / frac_ptr->width) * \
		(frac_ptr->x_max - frac_ptr->x_min);
	c.y = frac_ptr->y_min + (y / frac_ptr->height) * \
		(frac_ptr->y_max - frac_ptr->y_min);
	return (c);
}
