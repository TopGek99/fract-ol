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
	while (i < 200 && z.real < 2 && z.real > -2 && z.imaginary < 2 && z.imaginary > -2 )
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
	int i;
	double	temp_r;
	double	temp_i;

	i = 0;
	while (i < 200 && point.real < 2 && point.real > -2 && point.imaginary < 2 && point.imaginary > -2 )
	{
		temp_r = point.real;
		temp_i = point.imaginary;
		point.real = (temp_r * temp_r) - (temp_i * temp_i) + c.real;
		point.imaginary = (2 * temp_r * temp_i) + c.imaginary;
		i++;
	}
	return (i);
}

void	show_mandelbrot(void *mlx, void *window)
{
	int i;
	int j;
	int iterations;
	int colour;
	complex_n point;

	colour = 16711600;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			point.real = ((double)i - 500) * 0.004;
			point.imaginary = ((double)j - 500) * 0.004;
			iterations = mendelbrot_stability_check(point);
			mlx_pixel_put(mlx, window, i, j, colour - (iterations * 83558));
			j++;
		}
		i++;
	}
}

void	show_julia(void *mlx, void *window, complex_n c)
{
	int i;
	int j;
	int iterations;
	int colour;
	complex_n point;

	colour = 16711600;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			point.real = ((double)i - 500) * 0.004;
			point.imaginary = ((double)j - 500) * 0.004;
			iterations = julia_stability_check(point, c);
			mlx_pixel_put(mlx, window, i, j, colour - (iterations * 83558));
			j++;
		}
		i++;
	}
}