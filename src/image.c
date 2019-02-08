/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/08 12:47:03 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drow_img(t_fractal *fractal)
{
	t_kernel	*kernel;

	kernel = (t_kernel*)malloc(sizeof(t_kernel));
	/*free*/
	start_kernel(kernel, fractal);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
							fractal->img_ptr, 0, 0);
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 20, 0xFFFFFF,
					"Move: < > ^ v");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 40, 0xFFFFFF,
					"Exit: esc");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 60, 0xFFFFFF,
					"Zoom: mouse wheel");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 80, 0xFFFFFF,
					"Colors: 8, 5");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 100, 0xFFFFFF,
					"Iteratins: 7, 4");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, 1000, 120, 0xFFFFFF,
					"Hide menu: space");
}
