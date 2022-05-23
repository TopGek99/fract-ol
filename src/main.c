#include "fractol.h"
#include <stdio.h>

int destroy_hook(mlx_t *mlx)
{
	if (mlx)
		exit(0);
	return (0);
}

int key_hook(int keycode, mlx_t *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->inst, mlx->win);
		exit(0);
	}
	return (0);
}

int mouse_hook(int button, int x, int y, mlx_t *mlx)
{
	double		mod;
	static int	apply_mod;
	int			i;

	if (button == 4 && x && y)
		apply_mod++;
	else if (button == 5)
		apply_mod--;
	mod = 1;
	i = 0;
	while (i < apply_mod)
	{
		mod *= 0.8;
		i++;
	}
	while (i > apply_mod)
	{
		mod *= 1.25;
		i--;
	}
	if (apply_mod > 0)
		put_fractal_to_window(mlx, mod, mlx->fractal_type * 80 - apply_mod);
	else
		put_fractal_to_window(mlx, mod, 0);
	return (0);
}

void show_fractal(int type, complex_n c)
{
	mlx_t	mlx;

	mlx.inst = mlx_init();
	mlx.win = mlx_new_window(mlx.inst, 1000, 1000, "fract-ol");
	mlx.c = c;
	mlx.fractal_type = type;
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, destroy_hook, &mlx);
	put_fractal_to_window(&mlx, 1, 0);
	mlx_loop(mlx.inst);
}

double	parse_c(char *num)
{
	int		i;
	int		dec_len;
	int		sign;
	char	*whole_str;
	char	*dec_str;
	double	whole_num;
	double	dec;

	if (!ft_strchr(num, '.'))
		return ((double)ft_atoi(num));
	i = 0;
	sign = 1;
	if (num[0] == '-')
		sign = -1;
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
	free(whole_str);
	free(dec_str);
	return (whole_num + (dec * sign));
}

int main(int argc, char *argv[])
{
	complex_n	c;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
	{
		c.real = 0;
		c.imaginary = 0;
		show_fractal(1, c);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
	{
		c.real = parse_c(argv[2]);
		c.imaginary = parse_c(argv[3]);
		show_fractal(0, c);
	}
	else
	{
		ft_printf("\ninvalid parameters\n\n");
		ft_printf("valid parameters include:\n");
		ft_printf("'mandelbrot': display the mandelbrot set\n");
		ft_printf("'julia' 'a' 'b': display the julia set for the point a + bi\n\n");
	}
	return (0);
}