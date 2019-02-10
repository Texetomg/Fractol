/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/10 15:49:38 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	init_kernel(kernel);
}
