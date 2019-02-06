/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:43:29 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/02/06 20:23:21 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    img_move(int key, t_fractal *fractal)
{
    double  i;
    
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

int		key_press(int key, t_fractal *fractal)
{
    if (key == 123 || key == 124 || key == 125 || key == 126)
        img_move(key, fractal);
    if (key == 91)
        fractal->recolor = fractal->recolor + 10000;
	if (key == 53)
		exit(1);
    mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	drow_img(fractal);
	return(0);
}