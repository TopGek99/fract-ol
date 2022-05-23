#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

typedef struct	complex {
	double	real;
	double	imaginary;
}				complex_n;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				data_t;

typedef struct	s_mlx {
	void		*inst;
	void		*win;
	complex_n	c;
	int			fractal_type;
}				mlx_t;

void	put_fractal_to_window(mlx_t *mlx, double modifier, int offset);

#endif