/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:43:29 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/08 16:05:49 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_move(int key, t_fractal *fractal)
{
	double	i;

	if (key == 123)
	{
		i = (fractal->x1 - fractal->x0) / 20;
		fractal->x0 = fractal->x0 - i;
		fractal->x1 = fractal->x1 - i;
	}
	if (key == 124)
	{
		i = (fractal->x1 - fractal->x0) / 20;
		fractal->x0 = fractal->x0 + i;
		fractal->x1 = fractal->x1 + i;
	}
	i = (fractal->y0 - fractal->y1) / 20;
	if (key == 126)
	{
		fractal->y0 = fractal->y0 - i;
		fractal->y1 = fractal->y1 - i;
	}
	if (key == 125)
	{
		fractal->y0 = fractal->y0 + i;
		fractal->y1 = fractal->y1 + i;
	}
}

void	change_iter(int key, t_fractal *fractal)
{
	if (key == 89)
		fractal->iteration++;
	if (key == 86)
		if (fractal->iteration > 1)
			fractal->iteration--;
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
}

void	change_color(int key, t_fractal *fractal)
{
	if (key == 91)
		fractal->recolor = fractal->recolor + 5000;
	if (key == 87)
		fractal->recolor = fractal->recolor - 5000;
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
}

void	change_fractal(int key, t_fractal *fractal)
{
	if (key == 18)
		fractal->name = 'm';
	if (key == 19)
		fractal->name = 'j';
	if (key == 20)
		fractal->name = 'b';
	init_fractal(fractal);
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
}

int		key_press(int key, t_fractal *fractal)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		img_move(key, fractal);
		mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
		drow_img(fractal);
	}
	if (key == 18 || key == 19 || key == 20)
		change_fractal(key, fractal);
	if (key == 89 || key == 86)
		change_iter(key, fractal);
	if (key == 91 || key == 87)
		change_color(key, fractal);
	if (key == 49)
	{
		mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
			fractal->img_ptr, 0, 0);
	}
	if (key == 53)
		exit(1);
	return (0);
}
