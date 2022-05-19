#include "fractol.h"
#include <stdio.h>

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



double	parse_c(char *num)
{
	int		i;
	int		dec_len;
	char	*whole_str;
	char	*dec_str;
	double	whole_num;
	double	dec;

	i = 0;
	while(num[i] != '.')
		i++;
	whole_str = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(whole_str, num, i + 1);
	whole_num = (double)ft_atoi(whole_str);
	i++;
	dec_len = ft_strlen(&num[i]);
	dec_str = (char *)malloc(sizeof(char) * dec_len);
	ft_strlcpy(dec_str, &num[i], dec_len + 1);
	dec = (double)ft_atoi(dec_str);
	i = 0;
	while (i < dec_len)
	{
		dec /= 10;
		i++;
	}
	return (whole_num + dec);
}

int main(int argc, char *argv[])
{
	complex_n	c;

	// printf("%d\n", (int)ft_strlen(argv[1]));
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) && argc == 2)
	{
		c.real = 0;
		c.imaginary = 0;
		show_fractal(0, c);
	}
	else if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) && argc == 4)
	{
		c.real = parse_c(argv[2]);
		c.imaginary = parse_c(argv[3]);
		show_fractal(1, c);
	}
	else
	{
		ft_printf("invalid parameters\n\n");
		ft_printf("valid parameters include:\n");
		ft_printf("'mandelbrot': display the mandelbrot set\n");
		ft_printf("'julia' 'a' 'b': display the julia set for the point a + bi\n");
	}
	return (0);
}