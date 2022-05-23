/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:42:24 by arowe             #+#    #+#             */
/*   Updated: 2022/05/23 15:42:28 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_fractal(int type, t_complex_n c)
{
	t_mlx_t	mlx;

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

double	d_to_str(char *str, int len)
{
	char	*d_str;
	double	num;

	d_str = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(d_str, str, len + 1);
	num = (double)ft_atoi(d_str);
	free(d_str);
	return (num);
}

double	parse_c(char *num)
{
	int		i;
	int		dec_len;
	int		sign;
	double	whole_num;
	double	dec;

	if (!ft_strchr(num, '.'))
		return ((double)ft_atoi(num));
	i = 0;
	sign = 1;
	if (num[0] == '-')
		sign = -1;
	while (num[i] != '.')
		i++;
	whole_num = d_to_str(num, i);
	dec_len = ft_strlen(&num[++i]);
	dec = d_to_str(&num[i], dec_len);
	i = 0;
	while (i < dec_len)
	{
		dec /= 10;
		i++;
	}
	return (whole_num + (dec * sign));
}

int	main(int argc, char *argv[])
{
	t_complex_n	c;

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
		ft_printf(
			"'julia' 'a' 'b': display the julia set for the point a + bi\n\n"
			);
	}
	return (0);
}
