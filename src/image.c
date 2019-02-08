/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/08 14:50:56 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	restart_fractal(t_fractal *fractal)
{
	fractal->x0 = -1.5;
	fractal->y0 = 1.5;
	fractal->x1 = 1.5;
	fractal->y1 = -1.5;
	fractal->x_coord = 0;
	fractal->y_coord = 0;
	fractal->flag = 0;
	fractal->recolor = 10;
	fractal->iteration = 350;
}

void	drow_img(t_fractal *fractal)
{
	t_kernel	*kernel;

	if (!(kernel = (t_kernel*)malloc(sizeof(t_kernel))))
		error("malloc error");
	start_kernel(kernel, fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
							fractal->img_ptr, 0, 0);
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 20, 0xFFFFFF,
					"Select fractals: 1/2/3");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 40, 0xFFFFFF,
					"Move: < > ^ v");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 60, 0xFFFFFF,
					"Exit: esc");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 80, 0xFFFFFF,
					"Zoom: mouse wheel");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 100, 0xFFFFFF,
					"Colors: 8/5");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 120, 0xFFFFFF,
					"Iterations: 7/4:");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1130, 120, 0xFFFFFF,
				ft_itoa(fractal->iteration));
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 970, 140, 0xFFFFFF,
					"Hide menu: space");
}
