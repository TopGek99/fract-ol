/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:44:37 by arowe             #+#    #+#             */
/*   Updated: 2022/05/23 16:44:40 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_hook(t_mlx_t *mlx)
{
	if (mlx)
		exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx_t *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->inst, mlx->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx_t *mlx)
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
	if (apply_mod > 0 && mlx->fractal_type == 1)
		put_fractal_to_window(mlx, mod, 80 - apply_mod);
	else
		put_fractal_to_window(mlx, mod, 0);
	return (0);
}
