#include "fractol.h"

int mandelbrot_stability_check(complex_n point)
{
	int i;
	complex_n z;
	double	temp_r;
	double	temp_i;

	i = 0;
	z.real = 0;
	z.imaginary = 0;
	while (i < 200 && z.real < 2 && z.real > -2 && z.imaginary < 2 && z.imaginary > -2)
	{
		temp_r = z.real;
		temp_i = z.imaginary;
		z.real = (temp_r * temp_r) - (temp_i * temp_i) + point.real;
		z.imaginary = (2 * temp_r * temp_i) + point.imaginary;
		i++;
	}
	return (i);
}

int julia_stability_check(complex_n point, complex_n c)
{
	int 	i;
	double	temp_r;
	double	temp_i;

	i = 0;
	while (i < 200 && point.real < 2 && point.real > -2 && point.imaginary < 2 && point.imaginary > -2)
	{
		temp_r = point.real;
		temp_i = point.imaginary;
		point.real = (temp_r * temp_r) - (temp_i * temp_i) + c.real;
		point.imaginary = (2 * temp_r * temp_i) + c.imaginary;
		i++;
	}
	return (i);
}

void	my_mlx_pixel_put(data_t *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_image(mlx_t *mlx, data_t *img)
{
	img->img = mlx_new_image(mlx->inst, 1000, 1000);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	put_fractal_to_window(mlx_t *mlx, double modifier, int offset)
{
	int i;
	int j;
	int iterations;
	int colour;
	complex_n point;
	data_t *img;

	colour = 16711600;
	i = 0;
	img = (data_t *)malloc(sizeof(data_t));
	init_image(mlx, img);
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			point.real = ((double)i - 500 + (offset/modifier)) * 0.004 * modifier;
			point.imaginary = ((double)j - 500) * 0.004 * modifier;
			if (mlx->fractal_type == 1)
				iterations = mandelbrot_stability_check(point);
			else
				iterations = julia_stability_check(point, mlx->c);
			my_mlx_pixel_put(img, i, j, colour - (iterations * 83558));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->inst, mlx->win, img->img, 0, 0);
}