/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:09:49 by arowe             #+#    #+#             */
/*   Updated: 2022/05/23 16:09:53 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colour(t_mlx_t *mlx, t_complex_n point)
{
	int	colour;

	if (mlx->fractal_type == 1)
		colour = 16711600 - (mandelbrot_stability_check(point) * 83558);
	else
		colour = 16711600 - (julia_stability_check(point, mlx->c) * 83558);
	return (colour);
}

void	my_mlx_pixel_put(t_data_t *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	init_image(t_mlx_t *mlx, t_data_t *img)
{
	img->img = mlx_new_image(mlx->inst, 1000, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
