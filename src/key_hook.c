/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:15:35 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 18:03:24 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_press(int key)
{
	if (key == 53)
		exit(1);
	return(0);
}

void	mouse_scroll(int key, int x, int y, t_fractal *fractal)
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;

	x0 = (fractal->x1 - fractal->x0) * ((double)(x) / 10000);
	x1 = (fractal->x1 - fractal->x0) * ((double)(1000 - x) / 10000);
	y0 = (fractal->y0 - fractal->y1) * ((double)(1000 - y) / 10000);
	y1 = (fractal->y0 - fractal->y1) * ((double)(y) / 10000);
	if (key == 5)
	{
		fractal->x0 = fractal->x0 + x0;
		fractal->x1 = fractal->x1 - x1;
		fractal->y0 = fractal->y0 - y0;
		fractal->y1 = fractal->y1 + y1;
	}
	if (key == 4)
	{
		fractal->x0 = fractal->x0 - x0;
		fractal->x1 = fractal->x1 + x1;
		fractal->y0 = fractal->y0 + y0;
		fractal->y1 = fractal->y1 - y1;
	}
}

int		mouse_hook(int key, int x, int y, t_fractal *fractal)
{
	if (key == 5 || key == 4)
		mouse_scroll(key, x, y, fractal);
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
	return(0);
}

int		mouse_move(int x, int y, t_fractal *fractal)
{
	if (fractal->name == 'j')
	{
		fractal->x_coord = ((double)x - 500) / 1000;
		fractal->y_coord = ((double)y - 500) / 1000;	
	}
	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
	ft_putchar(fractal->name);
	return(0);
}

void    hook(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, 2, 0, key_press, fractal);
	mlx_hook(fractal->win_ptr, 4, 0, mouse_hook, fractal);
	mlx_hook(fractal->win_ptr, 6, 0, mouse_move, fractal);
}
