/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:42:49 by arowe             #+#    #+#             */
/*   Updated: 2022/05/23 15:42:54 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct complex {
	double	real;
	double	imaginary;
}				t_complex_n;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data_t;

typedef struct s_mlx {
	void		*inst;
	void		*win;
	t_complex_n	c;
	int			fractal_type;
}				t_mlx_t;

void	put_fractal_to_window(t_mlx_t *mlx, double modifier, int offset);
int		mandelbrot_stability_check(t_complex_n point);
int		julia_stability_check(t_complex_n point, t_complex_n c);
int		colour(t_mlx_t *mlx, t_complex_n point);
void	my_mlx_pixel_put(t_data_t *data, int x, int y, int colour);
void	init_image(t_mlx_t *mlx, t_data_t *img);
int		destroy_hook(t_mlx_t *mlx);
int		key_hook(int keycode, t_mlx_t *mlx);
int		mouse_hook(int button, int x, int y, t_mlx_t *mlx);

#endif
