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

int mandelbrot_stability_check(complex_n point);
int julia_stability_check(complex_n point, complex_n c);
void	show_mandelbrot(void *mlx, void *window);
void	show_julia(void *mlx, void *window, complex_n c);
#endif