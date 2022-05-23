/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:42:08 by arowe             #+#    #+#             */
/*   Updated: 2022/05/23 15:42:11 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_stability_check(t_complex_n point)
{
	int			i;
	t_complex_n	z;
	double		temp_r;
	double		temp_i;

	i = 0;
	z.real = 0;
	z.imaginary = 0;
	while (i < 200 && z.real < 2 && z.real > -2
		&& z.imaginary < 2 && z.imaginary > -2)
	{
		temp_r = z.real;
		temp_i = z.imaginary;
		z.real = (temp_r * temp_r) - (temp_i * temp_i) + point.real;
		z.imaginary = (2 * temp_r * temp_i) + point.imaginary;
		i++;
	}
	return (i);
}

int	julia_stability_check(t_complex_n point, t_complex_n c)
{
	int		i;
	double	temp_r;
	double	temp_i;

	i = 0;
	while (i < 200 && point.real < 2 && point.real > -2
		&& point.imaginary < 2 && point.imaginary > -2)
	{
		temp_r = point.real;
		temp_i = point.imaginary;
		point.real = (temp_r * temp_r) - (temp_i * temp_i) + c.real;
		point.imaginary = (2 * temp_r * temp_i) + c.imaginary;
		i++;
	}
	return (i);
}

void	put_fractal_to_window(t_mlx_t *mlx, double modifier, int offset)
{
	int			i;
	int			j;
	t_complex_n	point;
	t_data_t		*img;

	i = 0;
	img = (t_data_t *)malloc(sizeof(t_data_t));
	init_image(mlx, img);
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			point.real = ((double)i - 500 + (offset / modifier))
				* 0.004 * modifier;
			point.imaginary = ((double)j - 500) * 0.004 * modifier;
			my_mlx_pixel_put(img, i, j++, colour(mlx, point));
		}
		i++;
	}
	mlx_put_image_to_window(mlx->inst, mlx->win, img->img, 0, 0);
}
