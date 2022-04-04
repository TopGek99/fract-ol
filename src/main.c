#include "fractol.h"

void show_fractal(int type, complex_n c)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "fract-ol");

	if (type == 0)
		show_mandelbrot(mlx, window);
	else
		show_julia(mlx, window, c);
	mlx_loop(mlx);
}

int is_julia(char *type)
{
	int i;

	i = 0;
	while (type[i])
}

void parse_c(char *real, char *imaginary)
{
	
}

int main(int argc, char *argv[])
{
	complex_n c;

	if (is_mandelbrot(argv[1]))
	{
		c.real = 0;
		c.imaginary = 0;
		show_fractal(0, c);
	}
	else if (is_julia(argv[1]))
	{

	}

	return (0);
}