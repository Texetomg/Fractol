/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:45:08 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/01 15:45:42 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	drow_img(t_mlx_win *mlx_win, t_img *img)
{
	int			x;
	int			y;
	t_fractal	*fractal;

	y = 0;
	if (!(fractal = (t_fractal*)malloc(sizeof(t_fractal))))
		malloc_error();
	fractal->x0 = WDTH / 2;
	fractal->y0 = HGHT / 2;
	while(y < HGHT)
	{
		x = 0;
		while(x < WDTH)
		{
			*((int*)(img->addr_ptr) + x + y * WDTH) = mandelbrot(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_win->mlx_ptr, mlx_win->win_ptr, img->img_ptr, 0, 0);
}
